#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> dp;


void sqrt_2(){
	
	for (int i = 1; i <= 317; i++) {
		dp[i*i] = 1;
	}
}

int main() {

	int num = 0;
	cin >> num;

	dp.resize(200000,0);
	dp[0] = 0;

	sqrt_2();

	for (int i = 2; i <= num; i++) {

		int db = int(pow(i, 0.5));

		int min_ = 999999;
		for (int j = db; j >= 1; j--) {
			int temp = dp[i - (j*j)] + 1;

			if (min_ >= temp) {
				min_ = temp;
			}
		}

		dp[i] = min_;
	}

	cout << dp[num] << endl;
}