#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int map[600][600][3] = { 0 };
// map[][][0] ���� �� ����
// map[][][1] ���� ����ִ� �� ����
int N = 0;
int Max = 0;

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

void DFS(int y, int x, int count) {

	//���� ī��Ʈ ����
	if (count > map[y][x][1]) {
		map[y][x][1] = count;

		//���� �� ī��Ʈ�� Max �� ���� ũ�� ����
		if (count > Max) {
			Max = count;
		}

		//�Ǵٰ� �Ա� �� ���� ����
		int temp = map[y][x][0];

		// �� �Ȱ��� ���� �Դϴ�
		// ��
		// �迭 ���� �̳� �̰� && ���� �볪�� ������ �̵��� �볪�� ���� ���� �۰� && ���� �̵��� ���� �̹� �� ���� ����ִ� ��찡 ���� ���
		if (y - 1 >= 0 && map[y - 1][x][0] > map[y][x][0] && map[y - 1][x][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y - 1, x, count + 1);
			map[y][x][0] = temp;
		}
		//��
		if (y + 1 < N && map[y + 1][x][0] > map[y][x][0] && map[y + 1][x][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y + 1, x, count + 1);
			map[y][x][0] = temp;
		}
		//��
		if (x - 1 >= 0 && map[y][x - 1][0] > map[y][x][0] && map[y][x - 1][1] < map[y][x][1] + 1) {
			map[y][x][0] = 0;
			DFS(y, x - 1, count + 1);
			map[y][x][0] = temp;
		}
		//��
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

	// �� �� �湮�ϰ� ��ٷ� ������ ���� ���� �ֱ� ������
	// �迭�� ��� �� �湮 �� ���� �ϸ鼭 üũ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(map[i][j][1] <= 1)
				DFS(i, j, 1);
		}
	}

	printf("%d\n", Max);
}

