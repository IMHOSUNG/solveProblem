#include <stdio.h>

int arr[10000][2] = { 0 };

int main()
{
	int num = 0;
	int m = 0;
	int n = 0;
	int count3 = 1;
	int i, j, k;
	unsigned long long int count1 = 1, count2 = 1;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (k = 0; k < num; k++)
	{
		n = arr[k][0];
		m = arr[k][1];
		count1 = 1;
		count2 = 1;
		count3 = 1;

		long long int count4 = 1;
		while (count3 <= n)
		{
			count4 *= m;
			count4 /= count3;

			m--;

			count3++;

		}
		printf("%lld\n", count4);
	}
}
