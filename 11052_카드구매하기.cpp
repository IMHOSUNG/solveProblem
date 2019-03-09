#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
int main() {

	int num;
	cin >> num;

	dp.resize(10000, 0);

	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;
		dp[i + 1] = input;
	}

	for (int i = 2; i <= num; i++) {

		int max = dp[i];
		for (int j = 1; j <= int(i*0.5); j++) {

			if (max < (dp[i - j] + dp[j])) {
				max = dp[i - j] + dp[j];
				dp[i] = max;
			}
		}
	}

	cout << dp[num] << endl;
}