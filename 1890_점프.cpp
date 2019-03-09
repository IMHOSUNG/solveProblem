//bfs �޸� �ʰ�... 
/*
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int answer = 0;

class Pos {
public:
	int x;
	int y;
	int value;

	Pos(int y, int x, int value) : y(y), x(x), value(value) {}
};
vector < vector <int> > map;
deque < Pos > queue;

void bfs(int size) {

	while (!queue.empty()) {
		
		Pos temp = queue.front();
		queue.pop_front();
		if (temp.value == 0) {
			answer++;
		}

		int jump = temp.value;

		if (temp.x + jump < size && temp.value != 0) {

			queue.push_back(Pos(temp.y, temp.x + jump, map[temp.y][temp.x + jump]));
		}
		if (temp.y + jump < size && temp.value != 0) {
			queue.push_back(Pos(temp.y + jump, temp.x, map[temp.y+jump][temp.x]));
		}
	}
}

int main() {

	int size;
	cin >> size;

	//make map
	map.resize(size);
	
	for (int i = 0; i < size; i++) {

		map[i].resize(size);
		for (int j = 0; j < size; j++) {

			int input;
			cin >> input;

			map[i][j] = input;
		}
	}

	queue.push_back(Pos(0,0,map[0][0]));
	bfs(size);

	cout << answer << endl;
}
*/

#include <iostream>
#include <vector>
using namespace std;

class Pos {
public:
	unsigned long wayNum;
	int value;
};
vector < vector <Pos> > map;

int main() {

	int size;
	cin >> size;

	//make map
	map.resize(size);

	for (int i = 0; i < size; i++) {

		map[i].resize(size);
		for (int j = 0; j < size; j++) {

			int input;
			cin >> input;

			map[i][j].value = input;
		}
	}

	map[0][0].wayNum = 1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			//�� ������ �������� �ڱ� �ڽ��� ������
			//���� �ڷῡ�� 3�̸� 3 + 3 + 6���� 12�� ������ �� Ȯ��
			if (i == size - 1 && j == size - 1) {
				break;
			}

			int jump = map[i][j].value;

			if (jump + i < size){
				map[jump + i][j].wayNum += map[i][j].wayNum;
			}
			if (jump + j < size) {
				map[i][jump + j].wayNum += map[i][j].wayNum;
			}
		}
	}
	
	//���� dp�� Ȯ��
	/*
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << map[i][j].wayNum << " ";
		}
		cout << endl;
	}*/

	cout << map[size - 1][size - 1].wayNum << endl;
}