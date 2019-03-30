// 하아.. 코드가 너무 더럽다...
// 좀 더 깔끔하게 짤 것
// 막판에 고생한 부분이 둘러 쌓여있을 때를 고려를 안해서 반례 찾는 것에서 고생함...
// 문제 좀더 잘 읽고 풀기

// 다른 사람 코드 참고하면서 깔끔한 코드 짜는 방법을 공부해 볼 것


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

class Pos {
public:
	int y, x, visited;
	Pos(int y, int x) : y(y), x(x), visited(0) {}
};

int minCount = 999999999;
int maxCore = 0;

int AllCoreVisited(vector<Pos>& core) {

	int count = 0;
	for (int i = 0; i < core.size(); i++) {

		if (core[i].visited == 1)
		{
			count++;
		}
	}

	return count;
}

int CheckDistance(vector< vector<int> >& map) {

	int count = 0;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == -1) {
				count++;
			}
		}
	}
	return count;
}

void print(vector< vector<int> >& map) {

	printf("\n");
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.size(); j++) {
			printf("%d\t ", map[i][j]);
		}
		printf("\n");
	}
}

void DFS(vector< vector<int> >& map, int c, vector<Pos> & core) {

	//4방향 검사
	if (c == core.size()) {
		
		int count = CheckDistance(map);
		int coreCount = AllCoreVisited(core);
		
		if (maxCore < coreCount) {
			maxCore = coreCount;
			minCount = count;
		}
		else if (maxCore == coreCount) {
			if (minCount > count) {
				minCount = count;
			}
		}

		return;
	}
	else {
		int a = 0;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {

				int flag = 1;

				for (int y = core[c].y - 1; y >= 0; y--) {

					if (map[y][core[c].x] != 0) {
						flag = 0;
						break;
					}
				}

				if (flag == 1) {
					a++;
					vector< vector<int> > t = map;
					vector< Pos > tc = core;
					tc[c].visited = 1;

					for (int y = core[c].y - 1; y >= 0; y--) {

						t[y][core[c].x] = -1;
					}


					DFS(t, c + 1, tc);
				}
			}

			if (i == 1) {

				int flag = 1;

				for (int y = core[c].y + 1; y < map.size(); y++) {

					if (map[y][core[c].x] != 0) {
						flag = 0;
						break;
					}
				}

				if (flag == 1) {
					a++;
					vector< vector<int> > t = map;
					vector< Pos > tc = core;
					tc[c].visited = 1;
					for (int y = core[c].y + 1; y < map.size(); y++) {

						t[y][core[c].x] = -1;
					}


					DFS(t, c + 1, tc);

				}
			}

			if (i == 2) {

				int flag = 1;

				for (int x = core[c].x - 1; x >= 0; x--) {

					if (map[core[c].y][x] != 0) {
						flag = 0;
						break;
					}
				}

				if (flag == 1) {
					a++;
					vector< vector<int> > t = map;
					vector< Pos > tc = core;
					tc[c].visited = 1;
					for (int x = core[c].x - 1; x >= 0; x--) {

						t[core[c].y][x] = -1;
					}

					DFS(t, c + 1, tc);

				}
			}

			if (i == 3) {

				int flag = 1;

				for (int x = core[c].x + 1; x < map.size(); x++) {

					if (map[core[c].y][x] != 0) {
						flag = 0;
						break;
					}
				}

				if (flag == 1) {
					a++;
					vector< vector<int> > t = map;
					vector< Pos > tc = core;
					tc[c].visited = 1;

					for (int x = core[c].x + 1; x < map.size(); x++) {

						t[core[c].y][x] = -1;
					}
					DFS(t, c + 1, tc);

				}
			}
		}
		if (a == 0) {
			DFS(map, c + 1, core);
		}
	}
}


int main() {

	int testCase;
	scanf("%d", &testCase);

	for (int i = 1; i <= testCase; i++) {

		int size = 0;
		scanf("%d", &size);

		//make map
		vector< vector < int > > map;
		vector<Pos> core;
		map.resize(size);
		for (int s = 0; s < size; s++) {
			map[s].resize(size);
		}

		for (int y = 0; y < size; y++) {
			for (int x = 0; x < size; x++) {

				int input;
				scanf("%d", &input);

				map[y][x] = input;
				if (input == 1 && !((y == 0 || y == size - 1) || (x == 0 || x == size - 1)))
					core.push_back(Pos(y, x));
			}
		}

		//DFS

		DFS(map, 0, core);


		cout << "#" << i << " " << minCount << endl;
		minCount = 99999999;
		maxCore = 0;
		core.clear();
		map.clear();
	}
}