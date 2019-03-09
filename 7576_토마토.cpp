#include <deque>
#include <iostream>
using namespace std;

//1은 익은거
//0은 안익은거
//-1은 토마토가 비어 있는 것

int box[2000][2000] = { 0 };

int max_ = 0;

class Pos {
public:
	int x;
	int y;
	int count;

	Pos(int y, int x, int count) : x(x), y(y), count(count) {}

};

deque<Pos> queue;
int check(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (box[i][j] == 0)
				return 1;
		}
	}

	return 0;
}

void bfs(int n, int m, int tomato_count) {

	//4방향 분석
		//체크를 해주면서 박스에 넣기
		//넣은 후에 날짜 하루 씩 더 해주기
		//카운트 세서 하기 = -1 제외한 카운트와 같을 경우에는 종료
		//queue에서 다 빠졌는데도 카운트 개수가 다르면 음수 출력
	while (!queue.empty()) {

		Pos temp = queue.front();
		queue.pop_front();

		if (temp.count > max_) {
			max_ = temp.count;
		}		

		if (temp.y + 1 < n && temp.y >= 0 && temp.x >= 0 && temp.x < m) {
			if (box[temp.y + 1][temp.x] == 0) {
				box[temp.y + 1][temp.x] = 1;
				queue.push_back(Pos(temp.y + 1, temp.x, temp.count + 1));
			}
		}
		if (temp.y< n && temp.y-1 >= 0 && temp.x >= 0 && temp.x < m) {
			if (box[temp.y-1][temp.x] == 0) {
				box[temp.y-1][temp.x] = 1;
				queue.push_back(Pos(temp.y - 1, temp.x, temp.count + 1));
			}
		}
		if (temp.y< n && temp.y >= 0 && temp.x >= 0 && temp.x+1 < m) {
			if (box[temp.y][temp.x+1] == 0) {
				box[temp.y][temp.x+1] = 1;
				queue.push_back(Pos(temp.y, temp.x+1, temp.count + 1));
			}
		}
		if (temp.y< n && temp.y >= 0 && temp.x-1 >= 0 && temp.x < m) {
			if (box[temp.y][temp.x-1] == 0) {
				box[temp.y][temp.x-1] = 1;
				queue.push_back(Pos(temp.y, temp.x-1, temp.count + 1));
			}
		}
	}

	if (check(n, m) == 1)
		cout << -1 << endl;
	else
		cout << max_ << endl;
}

int main() {

	int n, m;
	cin >> n >> m;

	int box_size = n * m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			box[i][j] = input;
			if (box[i][j] == 1) {
				queue.push_back(Pos(i,j,0));
			}

			if (box[i][j] == -1) {
				box_size--;
			}
		}
	}
	//맵 생성 완
	bfs(m, n, box_size);
}