#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[600][600][3] = { 0 };
// map[][][0] 기존 맵 정보
// map[][][1] 현재 살아있는 날 정보
int N = 0;
int Max = 0;

// 맵 만들기 [0] 맵 정보
void MakeMap() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input = 0;
			scanf("%d", &input);
			map[i][j][0] = input;
		}
	}
}

void DFS(int y, int x, int count) {

	//현재 카운트 저장
	if (count > map[y][x][1]) {
		map[y][x][1] = count;

		//만약 그 카운트가 Max 값 보다 크면 저장
		if (count > Max) {
			Max = count;
		}

		//판다가 먹기 전 정보 저장
		int temp = map[y][x][0];

		// 다 똑같은 원리 입니다
		// 상
		// 배열 범위 이내 이고 && 현재 대나무 개수가 이동할 대나무 개수 보다 작고 && 다음 이동할 곳에 이미 더 오래 살아있는 경우가 없는 경우
		if (y - 1 >= 0 && map[y - 1][x][0] > map[y][x][0] && map[y - 1][x][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y - 1, x, count + 1);
			map[y][x][0] = temp;
		}
		//하
		if (y + 1 < N && map[y + 1][x][0] > map[y][x][0] && map[y + 1][x][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y + 1, x, count + 1);
			map[y][x][0] = temp;
		}
		//좌
		if (x - 1 >= 0 && map[y][x - 1][0] > map[y][x][0] && map[y][x - 1][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y, x - 1, count + 1);
			map[y][x][0] = temp;
		}
		//우
		if (x + 1 < N && map[y][x + 1][0] > map[y][x][0] && map[y][x + 1][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y, x + 1, count + 1);
			map[y][x][0] = temp;
		}
	}

}

int main() {

	scanf("%d", &N);

	MakeMap();

	// 한 점 방문하고 곧바로 주위에 못갈 수도 있기 때문에
	// 배열의 모든 점 방문 한 번씩 하면서 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(map[i][j][1] <= 1)
				DFS(i, j, 1);
		}
	}

	printf("%d\n", Max);
}

