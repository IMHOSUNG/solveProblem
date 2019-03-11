/*
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> dp;
int main() {

	dp.resize(1000);
	dp[1] = 9;

	int num;
	cin >> num;

	for (int i = 2; i <= num; i++) {

		dp[i] = (((dp[i - 1] * 2)% 1000000000) - ((int)(pow(2, i - 2))% 1000000000))%1000000000;
	}

	cout << dp[num] << endl;
}*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int x[101][11];

int main()
{
	int n, i, j;
	int sum;
	scanf("%d", &n);

	x[0][0] = 0;
	x[0][1] = x[0][2] = x[0][3] = x[0][4] = x[0][5] = x[0][6] = x[0][7] = x[0][8] = x[0][9] = 1;
	sum = 9;
	if (n > 1)
	{
		for (i = 1; i < n; i++)
		{
			sum = 0;
			for (j = 0; j < 10; j++)
			{
				x[i][j] = x[i - 1][j - 1] % 1000000000 + x[i - 1][j + 1] % 1000000000;

				sum += x[i][j];
				sum %= 1000000000;
			}
		}
	}
	printf("%d\n", sum);

	return 0;
}