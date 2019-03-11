#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> a;
vector<char> op;

char oper[6] = { '+',  '-' ,  '*' ,  '/' , '(' , ')'};

int check(char in) {

	for (int i = 0; i < 5; i++) {
		
		//여는 괄호
		if (in == oper[4]) {
			return 1;
		}
		//닫는 괄호
		else if (in == oper[5]) {
			return 2;
		}
		// + - 
		else if (in == oper[0] || in == oper[1]){
			return 3;
		}
		// * /
		else if (in == oper[2] || in == oper[3]) {
			return 4;
		}
	}

	return 0;
}

int find_openIndex() {

	//여는 괄호 인덱스 찾기
	for (vector<char>::size_type i = op.size() - 1; i >= 0; i--) {

		if (op[i] == '(') {
			return i;
		}
	}

	return -1;
}

void function(string input) {
	
	for (int index = 0; index < input.size(); index++)
	{
		//연산자
		if (check(input[index]) != 0) {
			int case_op = check(input[index]);
			//닫는 괄호
			if (case_op == 1) {
				op.push_back(input[index]);
			}
			else if (case_op == 2) {

				int in = find_openIndex();

				for (int t = op.size() - 1; t > in; t--) {
					a.push_back(op[t]);
					op.pop_back();
				}
				op.pop_back();
			}
			else if (case_op == 3) {

				if (op.size() != 0 && check(op[op.size() - 1]) == 4) {

					for (int x = op.size() - 1; x >= 0; x--)
					{
						if (check(op[x]) == 1)
							break;

						a.push_back(op[x]);
						op.pop_back();
					}
					op.push_back(input[index]);
				}
				else if (op.size() == 0 || check(op[op.size() - 1]) == 1) {
					op.push_back(input[index]);
				}
				else if (op.size() != 0 && check(op[op.size() - 1]) == 3) {
					a.push_back(op[op.size() - 1]);
					op.pop_back();
					op.push_back(input[index]);
				}
			}
			else if (case_op == 4) {

				if (op.size() != 0 && check(op[op.size() - 1]) == 4) {
					a.push_back(op[op.size() - 1]);
					op.pop_back();
				}
				op.push_back(input[index]);
			}
		}
		//알파벳
		else {
			a.push_back(input[index]);
		}
	}

	for (int i = op.size() - 1; i >= 0; i--) {
		a.push_back(op[i]);
		op.pop_back();
	}

	for (vector<char>::size_type i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << endl;
	a.clear();
	op.clear();
}

int main() {

	//괄호가 열리고 닫혔을 때 그 안의 연산자를 pop 해주고
	//남아 있는 연산자는 모두 마지막에 붙여 버린다.
	// 문제 잘못 이해 >> * / + - 의 우선 순위도 구별 해줄 것 !!

	string input;
	cin >> input;

	function(input);

}