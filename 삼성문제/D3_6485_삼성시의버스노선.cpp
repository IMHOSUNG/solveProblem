#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int testCase = 0;
	scanf("%d", &testCase);
	for (int t = 1; t <= testCase; t++) {
		
		vector<int> arr;
		arr.resize(5000);
		vector<int> answer;
		answer.resize(5000);
		int N = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {

			int front = 0, end = 0;
			scanf("%d %d", &front, &end);

			for (int j = front; j <= end; j++) {
				arr[j] += 1;
			}
		}

		int P = 0;
		scanf("%d", &P);

		for (int p = 0; p < P; p++) {
			int input = 0;
			scanf("%d", &input);
			answer[p] = arr[input];
		}

		printf("#%d", t);
		for (int a = 0; a < P; a++) {
			printf(" %d", answer[a]);
		}
		printf("\n");
		arr.clear();
		answer.clear();
	}
}