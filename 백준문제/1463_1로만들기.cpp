#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> d;

void function_dp(int i) {

	int min_ = d[i - 1];

	if (i % 2 == 0) {

		min_ = min(d[i / 2], min_);
	}
	if (i % 3 == 0) {

		min_ = min(d[i / 3], min_);
	}

	d.push_back(min_ + 1);
}

int main() {

	int num;
	cin >> num;
	d.resize(1);
	d.push_back(0);

	for (int i = 2; i <= num; i++) {
		function_dp(i);
	}

	cout << d[num] << endl;
}