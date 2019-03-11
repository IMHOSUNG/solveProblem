#include <deque>
#include <iostream>
#include <string>
using namespace std;
int map[105][105] = { 0 };


//ť�� �ֱ� ���� üũ�� ������ ������ ������ �߻��Ѵ�.
//�ֳ��ϸ� 4������ �� �� �ʿ� ���� ���� ���鼭 �޸� �ʰ� ������ ���
// �ذ�� : ť�� �ֱ� ���� üũ �Ǵ� ���� �ٲ��ְ� ť�� �־��ش�.

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
		
		//���� queue�� ���� ���� ���� ���� ��Ƶΰ�
		Pos temp = queue.front();
		queue.pop_front();
		//�̹� Ȯ���� �߱� ������ map���� ����
		if (temp.y == n - 1 && temp.x == m - 1) {
			min_ = temp.count;
			break;
		}

		//4���� Ȯ�� + ����ó��
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
	//�� �ֱ� ���� Ȯ��
	queue.push_back(Pos(0, 0, 1));
	function_bfs(n,m);
}