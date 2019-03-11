#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr;

int count_ = 0;

// 각 한 현을 처리할 stack 함수
void stack_function(vector<int>& str, int plat_num) {

	//비어 있을 때

	for (int i = str.size() - 1; i >= 0; i--) {

		//stack의 현재 탑보다 클 때
		if (plat_num > str[i]) {
			//카운트 올려주고
			count_++;
			//걍 넣는다.
			str.push_back(plat_num);
			break;
		}// 같을 때
		else if (plat_num == str[i]) {
			//아무것도 안한다.
			break;
		}//작을 때
		else if (plat_num < str[i]) {
			//이 때는 같을 때 까지 빼줘야 한다.
			//우선 원래 탑에 있던 것을 때니까 count 더해주고
			count_++;
			//pop 한다.
			str.pop_back();
		}
	}

	if (str.size() == 0) {
		count_++;
		str.push_back(plat_num);
	}
}


void function(int str_index, int plat_num) {

	if (str_index == 0) {
		stack_function(arr[0], plat_num);
	}
	else if (str_index == 1) {
		stack_function(arr[1], plat_num);
	}
	else if (str_index == 2) {
		stack_function(arr[2], plat_num);
	}
	else if (str_index == 3) {
		stack_function(arr[3], plat_num);
	}
	else if (str_index == 4) {
		stack_function(arr[4], plat_num);
	}
	else if (str_index == 5) {
		stack_function(arr[5], plat_num);
	}
}

int main() {

	int n, p;
	cin >> n >> p;

	arr.resize(6);
	for (int i = 0; i < n; i++) {
		int string_num, plat_num;

		cin >> string_num >> plat_num;

		int str_index = string_num - 1;

		function(str_index, plat_num);
	}

	cout << count_ << endl;
}