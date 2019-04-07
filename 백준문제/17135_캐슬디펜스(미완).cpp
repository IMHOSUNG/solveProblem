// 27% 까지만 통과... ㅠ ㅠ
// 문제 해석의 오류 
// 턴이라는 것은 궁수가 동시에 화살을 쏜다는 것
// 따라서 완전 탐색을 해야 함..

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector < vector <int>  > map;

struct Pos {
	int y, x;
	Pos(int y ,int x) : y(y) , x(x) {}
};

vector < Pos> a;
int N, M, D;
int Max = 0;

int distance(int y, int x, int y1, int x1) {
	
	return abs(y - y1) + abs(x - x1);
}

bool check(int y, int x) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i].y == y && a[i].x == x)
		{
			return false;
		}
	}

	return true;
}

void Function(int current, int& Count, int i, vector< vector <int> > & map) {
	for (int y = current - 1; y >= current - D && y >= 0; y--) {

		for (int x = 0; x < M; x++) {
			//여기만 어떻게 할 지 생각
			if (map[y][x] == 1 && distance(y, x, current, i) <= D) {
				map[y][x] = 0;
					Count++;
				
				return;
			}
		}
	}
}

void DFS(int currentLine, int currentX, int numArcher, int count) {


	if (!(numArcher == 3)) {

		for (int i = currentX; i < M; i++) {

			if (map[N][i] == 0) {
				map[N][i] = 1;
				DFS(currentLine, i, numArcher + 1, count);
				map[N][i] = 0;
			}
		}

	}
	else if(numArcher == 3){

		//3명의 궁수가 만족 할 때
		int Count = 0;
		int ArcherY = N;
		vector< vector <int > > temp = map;

		for (int current = ArcherY; current >= 0; current--) {	
			for (int i = 0; i < M; i++) {
				if (temp[ArcherY][i] == 1) {
					Function(current, Count, i, temp);
				}
			}

			//3개 체크
			//for (int i = 0; i < a.size(); i++) {	
			//	temp[a[i].y][a[i].x] = 0;
			//}
		}

		if (Count > Max) {
			Max = Count;
		}
		return;
	}
	
}

int main() {

	cin >> N >> M >> D;
	map.resize(N+1);
	for (int i = 0; i < N; i++) {
		
		map[i].resize(M);
		for (int j = 0; j < M; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}

	map[N].resize(M);

	DFS(N, 0, 0, 0);

	cout << Max << endl;
}