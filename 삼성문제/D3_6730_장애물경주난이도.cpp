#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int map[1005] = { 0 };

int main() {

	int testCase;
	scanf("%d", &testCase);
	for (int t = 1; t <= testCase; t++) {

		int N = 0;
		scanf("%d", &N);
		int MaxD = 0, MaxU = 0;
		for (int i = 0; i < N; i++) {

			int input = 0;
			scanf("%d", &input);
			map[i] = input;
		}

		for (int i = 0; i < N - 1; i++) {

			//내려 가는 경우
			if (map[i] > map[i + 1]) {

				if (map[i] - map[i + 1] > MaxD) {
					MaxD = map[i] - map[i + 1];
				}
			}
			//올라 가는 경우
			else if (map[i] < map[i + 1]) {

				if (map[i + 1] - map[i] > MaxU) {
					MaxU = map[i + 1] - map[i];
				}
			}
		}

		cout << "#" << t << " " << MaxU << " " << MaxD << endl;

		//memeset 은 string.h에 들어있음..
		memset(map, 0, sizeof(map));
	}
}