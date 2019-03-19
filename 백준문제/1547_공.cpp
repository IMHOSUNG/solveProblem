#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> Cup;

int findIndex(int num) {
	for (int i = 1; i < 4; i++) {

		if (Cup[i] == num)
			return i;
	}

	return 0;
}

int main() {

	int BallIndex = 1;

	Cup.resize(4);

	for (int i = 1; i < 4; i++) {
		Cup[i] = i;
	}

	int SwapNum;
	cin >> SwapNum;

	for (int i = 0; i < SwapNum; i++) {

		int From, To;
		cin >> From >> To;
		
		int f = findIndex(From);
		int t = findIndex(To);

		if (f == 0 || t == 0) {
			cout << -1 << endl;
			break;
		}

		swap(Cup[f], Cup[t]);

	}

	cout << Cup[BallIndex] << endl;
}