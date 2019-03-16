#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char arr[100][100] = { 0 };
	int n = 0, m = 0;
	int i, j, x, y;
	int count_w = 0;
	int count_b = 0;
	int rcount_w = 0;
	int rcount_b = 0;
	int min_1 = 66;
	int min_2 = 0;

	char arr1[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W' };

	char arr2[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
	};

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", &arr[i]);
	}

	for (i = 0; i < n - 7; i++)
	{
		for (j = 0; j < m - 7; j++)
		{

			for (x = 0; x < 8; x++)
			{
				for (y = 0; y < 8; y++)
				{
					if (arr[i + x][j + y] != arr1[x][y])
					{
						count_w++;

					}
					if (arr[i + x][j + y] != arr2[x][y])
					{
						count_b++;

					}
				}
			}
			rcount_w = count_w;
			rcount_b = count_b;
			count_w = 0;
			count_b = 0;

			if (rcount_w > rcount_b)
			{
				min_2 = rcount_b;
			}
			else
			{
				min_2 = rcount_w;
			}

			if (min_1 > min_2)
			{
				min_1 = min_2;
			}
		}

	}
	printf("%d\n", min_1);

}