#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector < vector < vector<int> > > map;

class Pos {
public:
	int x;
	int y;
	int z;
	int count;

	Pos(int y, int x, int z, int count) : y(y), x(x), z(z), count(count) {}
};

deque <Pos> queue;
int max_ = 0;

int check() {
	
	for (int i = 0; i < map.size(); i++) {

		for (int j = 0; j < map[i].size(); j++) {

			for (int k = 0; k < map[i][j].size(); k++) {

				if (map[i][j][k] == 0) {
					return 0;
				}
			}
		}
	}

	return 1;
}
void bfs(int m, int n, int h) {

	while (!queue.empty()) {

		//���� ������ 6����
		//�����¿�
		//���� �Ʒ���
		//üũ �ϰ� �־��ֱ� (���ǹ��� �ݺ� ����)
		Pos temp = queue.front();
		queue.pop_front();

		if (temp.count > max_) {
			max_ = temp.count;
		}

		// ����
		if (temp.z + 1 < h)
		{
			if (map[temp.z + 1][temp.y][temp.x] == 0)
			{
				map[temp.z + 1][temp.y][temp.x] = 1;
				queue.push_back(Pos(temp.y, temp.x, temp.z+1, temp.count+1));
			}
		}
		// �Ʒ���
		if (temp.z - 1 >= 0)
		{
			if (map[temp.z - 1][temp.y][temp.x] == 0)
			{
				map[temp.z - 1][temp.y][temp.x] = 1;
				queue.push_back(Pos(temp.y, temp.x, temp.z-1, temp.count+1));
			}
		}
		// ��
		if (temp.y - 1 >= 0)
		{
			if (map[temp.z][temp.y - 1][temp.x] == 0)
			{
				map[temp.z][temp.y-1][temp.x] = 1;
				queue.push_back(Pos(temp.y-1, temp.x, temp.z, temp.count + 1));
			}
		}
		//��
		if (temp.y + 1 < n)
		{
			if (map[temp.z][temp.y + 1][temp.x] == 0)
			{
				map[temp.z][temp.y + 1][temp.x] = 1;
				queue.push_back(Pos(temp.y+1, temp.x, temp.z, temp.count + 1));
			}
		}
		//��
		if (temp.x - 1 >= 0)
		{
			if (map[temp.z][temp.y][temp.x-1] == 0)
			{
				map[temp.z][temp.y][temp.x-1] = 1;
				queue.push_back(Pos(temp.y, temp.x-1, temp.z, temp.count + 1));
			}
		}
		//��
		if (temp.x + 1 < m)
		{
			if (map[temp.z][temp.y][temp.x + 1] == 0)
			{
				map[temp.z][temp.y][temp.x + 1] = 1;
				queue.push_back(Pos(temp.y, temp.x+1, temp.z, temp.count + 1));
			}
		}
		
	}

	//��� ĭ�� 0�� ����
	if (check()) {
		cout << max_ << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main(){

	int m, n, h;

	cin >> m >> n >> h;

	

	//���� �� ���� Ȯ��
	map.resize(h);
	for (int k = 0; k < h; k++)
	{
		map[k].resize(n);
		for (int i = 0; i < n; i++) {
			
			map[k][i].resize(m);
			for (int j = 0; j < m; j++) {
				int input;
				cin >> input;
				if (input == 1) {
					queue.push_back(Pos(i, j, k, 0));
				}
				map[k][i][j] = input;
			}
		}
	}

	bfs(m, n, h);
}