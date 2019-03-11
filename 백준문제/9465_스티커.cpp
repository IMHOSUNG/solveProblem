#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int function(int input) {
	
	vector< vector<int> > arr;
	arr.resize(2);

	
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < input; x++) {
			int in;
			cin >> in;
			arr[y].push_back(in);
		}
	}

	for (int x = 1; x < input; x++) {
		for (int y = 0; y < 2; y++) {
			if (y == 0) {
				
				arr[0][x] = max(arr[1][x - 1] + arr[0][x], arr[0][x - 1]);
			}
			else {
				arr[1][x] = max(arr[0][x - 1] + arr[1][x], arr[1][x - 1]);
			}
		}
	}

	if (arr[0][input - 1] > arr[1][input - 1]) {
		return arr[0][input - 1];
	}
	else {
		return arr[1][input - 1];
	}

}

int main() {

	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {

		int input;
		cin >> input;
		cout << function(input) << endl;
	}

}