#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr;

int count_ = 0;

// �� �� ���� ó���� stack �Լ�
void stack_function(vector<int>& str, int plat_num) {

	//��� ���� ��

	for (int i = str.size() - 1; i >= 0; i--) {

		//stack�� ���� ž���� Ŭ ��
		if (plat_num > str[i]) {
			//ī��Ʈ �÷��ְ�
			count_++;
			//�� �ִ´�.
			str.push_back(plat_num);
			break;
		}// ���� ��
		else if (plat_num == str[i]) {
			//�ƹ��͵� ���Ѵ�.
			break;
		}//���� ��
		else if (plat_num < str[i]) {
			//�� ���� ���� �� ���� ����� �Ѵ�.
			//�켱 ���� ž�� �ִ� ���� ���ϱ� count �����ְ�
			count_++;
			//pop �Ѵ�.
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