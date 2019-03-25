#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> map;

long primeCount(int input) {

	map.resize(1000000);

		int start = input;
		int end = input * 2;

		long count = 0;
		for (int prime = 2; prime*prime <= end; prime++) {

			int primestart = start / (prime);
			if (primestart*(prime) != (start))
				primestart++;

			for (int s = primestart; s*prime <= end; s++) {
				map[(s*prime) - start] = 1;
			}
		}

		for (int i = 1; i <= end - start; i++) {

			if (map[i] == 0) {
				count++;
			}
		}

		map.clear();
		return count;
	
}

int main() {

	while (1) {

		int input;
		scanf("%d", &input);

		if (input == 0)
			break;

		long answer = primeCount(input);

		printf("%d\n", answer);
	}
}