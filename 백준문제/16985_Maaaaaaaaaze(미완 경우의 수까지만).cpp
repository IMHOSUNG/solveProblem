#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector < vector < vector <int > > > map;
vector < vector < vector <int > > > cube;
int MazeInfo[5] = { 0 };
int RotateInfo[5] = { 0 };
int MazeInfoVisited[5] = { 0 };
// 회전 
// 1 이 초기 2가 한 번 회전 3이 2번 회전 4가 3번 회전

vector< vector <int >> Rotation(vector< vector <int> > & map, int Times) {

	vector< vector <int > > temp = map;
	if (Times == 1) {
		return temp;
	}
	else {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				temp[y][x] = map[x][5 - y];
			}
		}
		Rotation(temp, Times - 1);
	}
}



void MakeSet(int StartMaze, int Depth, int rotateTimes) {

	for (int i = 0; i < 5; i++) {
		MazeInfoVisited[StartMaze-1] = 1;
		MazeInfo[Depth] = StartMaze;
		RotateInfo[Depth] = rotateTimes;
		if (MazeInfoVisited[i] == 0) {

			for (int j = 1; j <= 4; j++) {
				MakeSet(i + 1, Depth + 1, j);
			}
		}
		MazeInfoVisited[StartMaze-1] = 0;
	}


	if (Depth >= 4) {
		

		//층과, 회전 정보
		/*
		cube.resize(6);
		for (int k = 0; k < 5; k++) {

			cube[k] = Rotation(map[MazeInfo[k]-1], RotateInfo[k]);
		}
		cube.clear();
		*/
		
		
		cout << "check" <<endl;

	}
}

int main() {

	map.resize(6);
	for (int N = 0; N < 5; N++) {
	
		map[N].resize(6);
		for (int i = 0; i < 5; i++) {

			map[N][i].resize(6);
			for (int j = 0; j < 5; j++) {

				int number = 0;
				scanf("%d", &number);

				map[N][i][j] = number;
			}
		}
	}

	for (int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 4; j++)
			MakeSet(i, 0, j);
	}

}