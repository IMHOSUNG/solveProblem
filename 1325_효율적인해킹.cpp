#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector < vector <int> > map;
deque < int > queue;
vector< int > answer;
vector< int > check_arr;

int max_ = 0;

void bfs(int n) {

	int count = 1;

	answer.resize(n + 1);

	for (int i = 1; i <= n; i++) {

		check_arr.resize(n + 1);
		//현재 컴퓨터 check
		check_arr[i] = 1;

		for (int a = 0; a < map[i].size(); a++) {

			//현재 컴퓨터와 연결되어 있는 컴 check
			check_arr[map[i][a]] = 1;
			//그리고 queue에 삽입
			queue.push_back(map[i][a]);
			count++;
		}

		//다음 부터 연결된 컴퓨터 탐색
		while (!queue.empty()) {

			//현재 큐에 들어가 있는 것 체크
			int temp = queue.front();
			queue.pop_front();

			//그 인덱스에 있는 것을 맵에서 찾아서 새로운 것이 발견되면 다시
			//큐에 삽입
			for (int b = 0; b < map[temp].size(); b++) {
				//현재 체크가 되어 있지 않는 컴퓨터만 체크 하고 
				//큐에 다시 넣어줌
				if (check_arr[map[temp][b]] == 0) {
					
					check_arr[map[temp][b]] = 1;
					queue.push_back(map[temp][b]);
					count++;
				}
			}
		}
		answer[i] = count;

		if (count > max_) {
			max_ = count;
		}

		count = 1;
		check_arr.clear();
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	map.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		//map[a].push_back(b);
		map[b].push_back(a);
	}

	bfs(n);

	for (int i = 1; i < answer.size(); i++) {

		if (max_ == answer[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}