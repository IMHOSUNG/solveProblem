#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[20][20] = { 0 };
int N = 0;
int Count = 0;

void MakeMap(int N) {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			int input;
			scanf("%d", &input);
			if (input == 1) {
				input = -1;
			}
			map[i][j] = input;
		}
	}
}


bool CheckRight(int y, int x) {
	
	if (x + 1 < N && map[y][x + 1] != -1)
	{
		return true;
	}

	return false;
}

bool CheckDown(int y, int x) {

	if (y + 1 < N && map[y+1][x] != -1)
	{
		return true;
	}

	return false;
}

bool CheckSide(int y, int x) {

	if (y + 1 < N && x + 1 < N) {

		if (map[y + 1][x + 1] != -1 && map[y][x + 1] != -1 && map[y + 1][x] != -1) {

			return true;
		}
	}
	
	return false;
}

/*	currentState : 우(0) , 대각선(1) , 아래 (2)
	y, x, : 현재 y ,x 좌표
*/
void DFS(int currentState, int y, int x) {

	if (x == N - 1 && y == N - 1) {
		Count++;
	}
	else {
		if (currentState == 0) {

			//우로 이동할 때
			if (CheckRight(y,x)) {
				DFS(0, y, x + 1);
			}

			if (CheckSide(y, x)) {
				DFS(1, y + 1, x + 1);
			}
		}
		if (currentState == 1) {

			if (CheckRight(y, x)) {
				DFS(0, y, x + 1);
			}

			if (CheckDown(y, x)) {
				DFS(2, y + 1, x);
			}

			if (CheckSide(y, x)) {
				DFS(1, y + 1, x + 1);
			}

		}
		if (currentState == 2) {

			if (CheckSide(y, x)) {
				DFS(1, y + 1, x + 1);
			}

			if (CheckDown(y, x)) {
				DFS(2, y + 1, x);
			}
		}
	}
}

int main() {

	scanf("%d", &N);

	//Map 입력 완료 (1 => -1 변경)
	MakeMap(N);
	DFS(0,0,1);

	printf("%d\n", Count);
}