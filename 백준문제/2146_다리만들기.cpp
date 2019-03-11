#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int group_num = 1;

int min_ = 99999999999;

class Pos {
public:
	int y;
	int x;
	int group;
	int distance;

	Pos(int y, int x, int group, int distance) : y(y), x(x), group(group), distance(distance) {}
};

deque < Pos > queue;

vector < vector < Pos > > map;

void makeMap(int n) {

	map.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input = 0;

			cin >> input;

			map[i].push_back(Pos(i, j, input, 0));
		}
	}
}

void printMap(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j].distance << " ";
		}
		cout << endl;
	}
}

void setGroup(int y, int x, int n) {

	map[y][x].group = group_num;
	
	if (x-1 >= 0 && map[y][x - 1].group == 1) {
		map[y][x - 1].group = group_num;
		setGroup(y, x - 1, n);
	}
	if (x + 1 < n && map[y][x + 1].group == 1) {
		map[y][x + 1].group = group_num;
		setGroup(y, x + 1, n);
	}
	if (y - 1 >= 0 && map[y - 1][x].group == 1) {
		map[y - 1][x].group = group_num;
		setGroup(y - 1, x, n);
	}
	if (y + 1 < n && map[y + 1][x].group == 1) {
		map[y + 1][x].group = group_num;
		setGroup(y + 1, x, n);
	}
}

//그룹을 만드는 함수
void makeGroup(int y, int x, int n) {

	group_num++;
	
	//DFS를 통해서 그룹 생성
	setGroup(y, x, n);
}

void fill_map(int n) {

	while (!queue.empty()) {
		
		Pos temp = queue.front();
		queue.pop_front();

		if (temp.y + 1 < n && map[temp.y + 1][temp.x].group == 0){
			map[temp.y + 1][temp.x].group = temp.group;
			map[temp.y + 1][temp.x].distance = temp.distance + 1;
			queue.push_back(Pos(temp.y + 1, temp.x, temp.group, temp.distance + 1));
		}
		if (temp.x + 1 < n && map[temp.y][temp.x+1].group == 0) {
			map[temp.y][temp.x+1].group = temp.group;
			map[temp.y][temp.x+1].distance = temp.distance + 1;
			queue.push_back(Pos(temp.y, temp.x+1, temp.group, temp.distance + 1));
		}
		if (temp.y - 1 >= n && map[temp.y - 1][temp.x].group == 0) {
			map[temp.y - 1][temp.x].group = temp.group;
			map[temp.y - 1][temp.x].distance = temp.distance + 1;
			queue.push_back(Pos(temp.y - 1, temp.x, temp.group, temp.distance + 1));
		}
		if (temp.x - 1 >= n && map[temp.y][temp.x-1].group == 0) {
			map[temp.y][temp.x - 1].group = temp.group;
			map[temp.y][temp.x - 1].distance = temp.distance + 1;
			queue.push_back(Pos(temp.y, temp.x - 1, temp.group, temp.distance + 1));
		}

		if (temp.y + 1 < n && map[temp.y + 1][temp.x].group != temp.group && map[temp.y + 1][temp.x].group != 0) {

			int a = map[temp.y + 1][temp.x].distance + temp.distance;

			if (a < min_)
				min_ = a;
		}
		if (temp.x + 1 < n && map[temp.y][temp.x + 1].group != temp.group && map[temp.y][temp.x + 1].group != 0) {

			int a = map[temp.y][temp.x + 1].distance + temp.distance;

			if (a < min_)
				min_ = a;

		}
		if (temp.y - 1 >= n && map[temp.y - 1][temp.x].group != temp.group && map[temp.y - 1][temp.x].group != 0) {

			int a = map[temp.y - 1][temp.x].distance + temp.distance;

			if (a < min_)
				min_ = a;
		}
		if (temp.x - 1 >= n && map[temp.y][temp.x - 1].group != temp.group  &&map[temp.y][temp.x - 1].group != 0) {

			int a = map[temp.y][temp.x-1].distance + temp.distance;

			if (a < min_)
				min_ = a;
		}
	}

	cout << min_ << endl;
}

int main() {
	
	int n;
	cin >> n;

	makeMap(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if(map[i][j].group == 1)
				//그룹 생성 함수 실행
				makeGroup(i,j,n);
		}
	}

	//현재 상태 확인
	//printMap(n);
	//4개
	//cout << group_num << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].group != 0) {
				queue.push_back(Pos(i, j, map[i][j].group, 0));
			}
		}
	}

	fill_map(n);

	//printMap(n);
}