#include <deque>
#include <iostream>
#include <string>
using namespace std;
int map[105][105] = { 0 };


//큐에 넣기 전에 체크를 해주지 않으면 문제가 발생한다.
//왜냐하면 4방향을 볼 때 필요 없는 것이 들어가면서 메모리 초과 오류가 뜬다
// 해결법 : 큐에 넣기 전에 체크 또는 맵을 바꿔주고 큐에 넣어준다.

class Pos {

public:
	int x;
	int y;
	int count;
	int check;

	Pos(int y, int x, int count) :  x(x) , y(y), count(count), check(0){}

	void setCount(int value) {
		this->count = value;
	}
};

deque<Pos> queue;

void print_map(int n, int m) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " " ;
		}
		cout << endl;
	}
}

int min_ = 9999999;

void function_bfs(int n, int m) {
	
	while (!queue.empty()) {
		
		//현재 queue의 가장 앞의 것을 빼서 잡아두고
		Pos temp = queue.front();
		queue.pop_front();
		//이미 확인을 했기 때문에 map에서 지움
		if (temp.y == n - 1 && temp.x == m - 1) {
			min_ = temp.count;
			break;
		}

		//4방향 확인 + 예외처리
		if (temp.y-1 >= 0 && temp.y < n && temp.x >= 0 && temp.x < m) {
			if (map[temp.y - 1][temp.x] == 1) {
				map[temp.y - 1][temp.x] = 0;
				queue.push_back(Pos(temp.y - 1, temp.x, temp.count+1));
			}
		}
		if (temp.y >= 0 && temp.y + 1 < n && temp.x >= 0 && temp.x < m) {
			if (map[temp.y + 1][temp.x] == 1) {
				map[temp.y + 1][temp.x] = 0;
				queue.push_back(Pos(temp.y + 1, temp.x, temp.count + 1));
			}
		}
		if (temp.y >= 0 && temp.y < n && temp.x-1 >= 0 && temp.x < m) {
			if (map[temp.y][temp.x-1] == 1) {
				map[temp.y][temp.x-1] = 0;
				queue.push_back(Pos(temp.y , temp.x-1, temp.count + 1));
			}
		}
		if (temp.y >= 0 && temp.y < n && temp.x >= 0 && temp.x+1 < m) {
			if (map[temp.y][temp.x+1] == 1) {
				map[temp.y][temp.x+1] = 0;
				queue.push_back(Pos(temp.y, temp.x+1, temp.count + 1));
			}
		}		
	}

	cout << min_ << endl;
}

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {

			map[i][j] = a[j]- '0' ;
		}
	}

	//print_map(n, m);
	//맵 넣기 까지 확인
	queue.push_back(Pos(0, 0, 1));
	function_bfs(n,m);
}