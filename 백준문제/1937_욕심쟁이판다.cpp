#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int map[600][600][3] = { 0 };
int Count = 0;
// map[][][0] ���� �� ����
// map[][][1] ���� ����ִ� �� ����
int N = 0;
int Max = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

// �� ����� [0] �� ����
void MakeMap() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input = 0;
			scanf("%d", &input);
			map[i][j][0] = input;
		}
	}
}

void print() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d  ", map[i][j][1]);
		}
		printf("\n");
	}

	printf("\n");
}

void DFS(int y, int x) {

	int i, ax, ay;

	for (int i = 0; i < 4; i++) {

		ax = x + dx[i]; ay = y + dy[i];

		if (ax < 0 || ax >= N || ay < 0 || ay >= N)
			continue;

		if (map[y][x][0] < map[ay][ax][0] ) {
				
			if (map[ay][ax][1] == 0) {
				map[ay][ax][1] = 1;
				DFS(ay, ax);
			}

			map[y][x][1] = max(map[y][x][1], map[ay][ax][1] + 1);
	
		}

		if (map[y][x][1] > Max) {
			Max = map[y][x][1];
		}
	}
}

int main() {

	scanf("%d", &N);

	MakeMap();

	// �� �� �湮�ϰ� ��ٷ� ������ ���� ���� �ֱ� ������
	// �迭�� ��� �� �湮 �� ���� �ϸ鼭 üũ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j][1] == 0)
				map[i][j][1] = 1;
				DFS(i, j);
		}
	}

	printf("%d\n", Max);
}

