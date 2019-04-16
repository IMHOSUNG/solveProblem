#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[10][10] = { 0 };
int paperNumInfo[7] = { 0 };
int Min = 10000;

int check(int y, int x) {

	for (int size = 1; size < 5; size++) {

		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				if (i > 9 || j > 9) {
					return 0;
				}
				else {
					if (map[i][j] == 0) {
						return size - 1;
					}
				}
			}
		}
	}
}

bool AllClear() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

bool OverPaper() {

	for (int i = 1; i < 6; i++) {
		if (paperNumInfo[i] > 5) {
			return true;
		}
	}
	return false;
}

int CountPaper() {

	int sum = 0;
	for (int i = 1; i < 6; i++) {
		sum += paperNumInfo[i];
	}
	return sum;
}

void mapCheck(int y, int x, int s, int value) {


	if (value == 0) {
		paperNumInfo[s]++;
	}

	if (value == 1) {
		paperNumInfo[s]--;
	}

	for (int a = y; a < y + s; a++) {
		for (int b = x; b < x + s; b++) {
			map[a][b] = value;
		}
	}
}

void DFS(int y, int x) {
	

	int paper = CountPaper();

	if (paper > Min || OverPaper()) {
		return;
	}

	if (AllClear()) {
		printf("%d\n", paper);		
		if (Min > paper) {
			Min = paper;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				int maxSize = check(i, j);
				if (maxSize != 0)
				{
					for (int s = maxSize; s >= 1; s--) {
						mapCheck(i, j, s, 0);
						DFS(i, j);
						mapCheck(i, j, s, 1);
					}
				}
			}
		}
	}
	
}

int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			
			scanf("%d", &map[i][j]);
		}
	}

	DFS(0, 0);

	if (Min == 10000)
		printf("%d\n", -1);
	else
		printf("%d\n", Min);
}