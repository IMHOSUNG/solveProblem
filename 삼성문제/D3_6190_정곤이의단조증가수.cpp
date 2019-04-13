#include <iostream>
#include <string.h>
using namespace std;

int arr[100000] = { 0 };

bool CheckUpNumber(int in) {

	int temp = in;
	int tempNum = 0;
	while (temp != 0) {

		int back = temp % 10;
		temp = temp / 10;
		int front = temp % 10;

		if (back < front) {
			return false;
		}
	}
	return true;
}

int main() {

	int testCase = 0;
	scanf("%d", &testCase);
	for (int t = 1; t <= testCase; t++) {

		int Max = -1;
		int N = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (CheckUpNumber(arr[i] * arr[j]) == true) {
					if (Max < arr[i] * arr[j]) {
						Max = arr[i] * arr[j];
					}
				}
			}
		}
		printf("#%d %d\n", t, Max);
		memset(arr, 0, sizeof(arr));
	}
}