#include <deque>
#include <iostream>
using namespace std;

//1�� ������
//0�� ��������
//-1�� �丶�䰡 ��� �ִ� ��

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

	//4���� �м�
		//üũ�� ���ָ鼭 �ڽ��� �ֱ�
		//���� �Ŀ� ��¥ �Ϸ� �� �� ���ֱ�
		//ī��Ʈ ���� �ϱ� = -1 ������ ī��Ʈ�� ���� ��쿡�� ����
		//queue���� �� �����µ��� ī��Ʈ ������ �ٸ��� ���� ���
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
	//�� ���� ��
	bfs(m, n, box_size);
}