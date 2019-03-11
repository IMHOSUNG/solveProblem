#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

vector<int> dp;
vector<int> coin_arr;

const int INF = numeric_limits<int>::max();

int check_have_coin(int index) {

	for (int i = 0; i < coin_arr.size(); i++) {

		if (index == coin_arr[i]) {
			dp[index] = 1;
			return 1;
		}
	}

	return 0;
}
void function(int coin) {

	int min_ = INF;

	for (int index = coin_arr[0]; index <= coin; index++)
	{
		if (!check_have_coin(index)) {

			for (int i = 0; i < coin_arr.size(); i++) {

				if (index - coin_arr[i] >= 0 && dp[index - coin_arr[i]] > 0) {

					if (min_ > dp[index - coin_arr[i]]) {
						min_ = dp[index - coin_arr[i]];
					}
				}
			}

			dp[index] = min_ + 1;
			min_ = INF;
		}
	}
}

int main() {

	int size, coin;
	cin >> size >> coin;

	
	for (int i = 0; i < size; i++) {
		int input;
		cin >> input;
		coin_arr.push_back(input);
	}

	sort(coin_arr.begin(), coin_arr.end());

	dp.resize(200000);

	function(coin);

	if (dp[coin] <= 0) {
		cout << -1 << endl;
	}
	else {
		cout << dp[coin] << endl;
	}
}