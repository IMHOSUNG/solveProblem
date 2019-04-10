#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int testCase = 0;
	scanf("%d", &testCase);

	for (int t = 1; t <= testCase; t++) {

		int N = 0;
		scanf("%d", &N);

		double answer = 0.0;

		for (int i = 0; i < N; i++) {

			double p1 = 0.0;
			int x1 = 0;

			scanf("%lf %d", &p1, &x1);

			answer += p1 * x1;

		}

		printf("#%d %lf\n", t, answer);
	}
}