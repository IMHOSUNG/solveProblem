#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector < vector < vector <int > > > map;
vector < vector < vector <int > > > cube;
int MazeInfo[5] = { 0 };
int RotateInfo[5] = { 0 };
int MazeInfoVisited[5] = { 0 };
// 회전 
// 1 이 초기 2가 한 번 회전 3이 2번 회전 4가 3번 회전

int MinCount = 999999999;
int flag = 0;

int dz[] = { -1 , 1 , 0 , 0 , 0, 0 };
int dy[] = { 0 , 0, -1 , +1 , 0 , 0 };
int dx[] = { 0, 0, 0, 0 ,-1 , 1 };

vector< vector <int >> Rotation(vector< vector <int> > map, int Times) {

	vector< vector <int > > temp;
	temp.resize(5);
	for (int i = 0; i < 5; i++) {
		temp[i].resize(5);
	}

	if (Times == 1) {
		return map;
	}
	else if (Times == 2) {

		for (int y = 0; y < 5; y++) {
			
			for (int x = 0; x < 5; x++) {
				temp[x][4 - y] = map[y][x];
			}
		}
		return temp;
	}
	else if (Times == 3) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				temp[4-y][4-x] = map[y][x];
			}
		}
		return temp;
	}
	else if (Times == 4) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				temp[4-x][y] = map[y][x];
			}
		}
		return temp;
	}

}

class Pos {
public:
	int z;
	int y;
	int x;
	int Count;

	Pos(int z, int y, int x, int Count) : z(z), y(y), x(x) , Count(Count){}

};

void BFS(int sz, int sy, int sx, int ez, int ey, int ex) {

	int visited[5][5][5] = { 0 };

	visited[sz][sy][sx] = 1;
	queue<Pos> q;

	for (int i = 0; i < 6; i++) {

		int az = sz + dz[i];
		int ay = sy + dy[i];
		int ax = sx + dx[i];

		if (az < 0 || az > 4 || ay < 0 || ay > 4 || ax < 0 || ax > 4)
			continue;

		if (cube[az][ay][ax] ==  1 && visited[az][ay][ax] == 0) {
			visited[az][ay][ax] = 1;
			q.push(Pos(az, ay, ax, 1));
		}
	}

	while (!q.empty()) {

		Pos temp = q.front();
		q.pop();
		//cout << temp.z << " " << temp.y << " " << temp.x << endl;

		if (temp.z == ez && temp.y == ey && temp.x == ex) {
			flag = 1;
			
			if (MinCount > temp.Count) {
				//cout << temp.Count << endl;
				MinCount = temp.Count;
			}
			break;
		}

		for (int i = 0; i < 6; i++) {

			int az = temp.z + dz[i];
			int ay = temp.y + dy[i];
			int ax = temp.x + dx[i];

			if (az < 0 || az > 4 || ay < 0 || ay > 4 || ax < 0 || ax > 4)
				continue;

			if (cube[az][ay][ax] == 1 && visited[az][ay][ax] == 0) {
				visited[az][ay][ax] = 1;
				q.push(Pos(az, ay, ax, temp.Count+1));
			}
		}
	}
}

void TCASE(int tcase) {

	if (tcase == 1) {
		if (cube[0][0][0] == 1 && cube[4][4][4] == 1) {
			BFS(0, 0, 0, 4, 4, 4);
		}
	}
}

void MakeCube(int Slice, int RotateTime, int depth) {

	cube[depth] = Rotation(map[Slice - 1], RotateTime);
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
		cube.resize(5);
		for (int i = 0; i < 5; i++)
		{
			MakeCube(MazeInfo[i],RotateInfo[i], i);
		}

		if (cube[0][0][0] == 1 && cube[4][4][4] == 1) {
			BFS(0, 0, 0, 4, 4, 4);
		}
		cube.clear();
	}
}

int main() {

	map.resize(5);
	for (int N = 0; N < 5; N++) {
	
		map[N].resize(5);
		for (int i = 0; i < 5; i++) {

			map[N][i].resize(5);
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

	if (flag == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", MinCount);
	}
}
