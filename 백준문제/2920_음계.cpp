#include <iostream>
using namespace std;

int arr[9];

int check() {

	for (int i = 0; i < 7; i++) {

		if (arr[i] + 1 != arr[i + 1]) {
			break;
		}

		if (i == 6) {
			return 1;
		}
	}

	for (int i = 0; i < 7; i++) {
		if (arr[i] - 1 != arr[i + 1]) {
			break;
		}

		if (i == 6) {
			return 2;
		}
	}

	return 3;
}

int main() {

	int input;
	for (int i = 0; i < 8; i++) {
		cin >> input;
		arr[i] = input;
	}

	int flag = check();

	if (flag == 1) {
		cout << "ascending" << endl;
	}

	else if (flag == 2) {
		cout << "descending" << endl;
	}
	else if (flag == 3) {
		cout << "mixed" << endl;
	}
}