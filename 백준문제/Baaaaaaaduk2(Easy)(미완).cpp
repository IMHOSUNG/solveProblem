#include <iostream>
#include <vector>
using namespace std;

vector< vector <int> > map;
vector< vector< int> > visited;
int n, m;
int dx[] = { -1 , 1, 0 ,0 };
int dy[] = { 0, 0, -1, 1 };

//디버그용
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool AllVisited() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				return false;
			}
		}
	}
	return true;
}


int Count = 0;


void DFS2(int y, int x) {

	for (int i = 0; i < 4; i++) {

	}
}

void DFS(int y, int x, int cur) {

	if (cur >= 2) {

		print();
		
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 2) {
					temp++;
				}
			}
		}

		if (temp > Count) {
			Count = temp;
		}
		return;
	}

	for (int i = y; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				for (int w = 0; w < 4; w++) {
					
					int ay = i + dy[w];
					int ax = j + dx[w];

					if (ay < 0 || ay >= n || ax < 0 || ax >= m)
						continue;

					if (map[ay][ax] != 0)
						continue;
						
					map[ay][ax] = 1;
					DFS(ay, ax, cur + 1);
					map[ay][ax] = 0;					
				}
			}
		}
	}

}


int main() {

	cin >> n >> m;

	map.resize(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		for (int j = 0; j < m; j++) {

			int input;
			cin >> input;
			map[i][j] = input;
		}
	}

	DFS(0, 0, 0);

	cout << Count << endl;
}