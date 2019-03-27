#include <iostream>
#include <string>
using namespace std;

//case 1 : ADOPQR
//case 2 : CEFGHIJKLMNSTUVWXYZ
//case 3 : B

string case1 = "ADOPQR";
string case2 = "CEFGHIJKLMNSTUVWXYZ";
string case3 = "B";

int FindCase(char ch) {

	string all = case1 + case2 + case3;

	int fIndex = 0;
	for (int i = 0; i < all.size(); i++) {
		if (ch == all[i]) {

			fIndex = i;
			break;
		}
	}

	if (fIndex <= 5) {
		return 1;
	}
	else if (fIndex == all.size() - 1) {
		return 3;
	}
	else {
		return 2;
	}
}

int Fun(string in[2], int i) {
	for (int start = 0; start < in[0].size(); start++) {

		int fcaseNum = FindCase(in[0][start]);
		int bcaseNum = FindCase(in[1][start]);

		if (fcaseNum != bcaseNum) {
			cout << "#" << i << " " << "DIFF" << endl;
			return 0;
		}
	}
	return 1;
}

int main() {

	int testCase;

	cin >> testCase;

	string in[2];
	int index = 0;

	for (int i = 1; i <= testCase; i++) {

		cin >> in[0] >> in[1];

		if (in[0].size() != in[1].size()) {
			cout << "#" << i << " " << "DIFF" << endl;
		}
		else {

			int flag = Fun(in, i);

			if (flag == 1) {
				cout << "#" << i << " " << "SAME" << endl;
			}
		}
	}
}