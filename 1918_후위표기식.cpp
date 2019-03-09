#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> a;
vector<char> op;

char oper[6] = { '+',  '-' ,  '*' ,  '/' , '(' , ')'};

int check(char in) {

	for (int i = 0; i < 5; i++) {
		
		//���� ��ȣ
		if (in == oper[4]) {
			return 1;
		}
		//�ݴ� ��ȣ
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

	//���� ��ȣ �ε��� ã��
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
		//������
		if (check(input[index]) != 0) {
			int case_op = check(input[index]);
			//�ݴ� ��ȣ
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
		//���ĺ�
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

	//��ȣ�� ������ ������ �� �� ���� �����ڸ� pop ���ְ�
	//���� �ִ� �����ڴ� ��� �������� �ٿ� ������.
	// ���� �߸� ���� >> * / + - �� �켱 ������ ���� ���� �� !!

	string input;
	cin >> input;

	function(input);

}