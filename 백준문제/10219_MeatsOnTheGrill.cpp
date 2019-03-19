#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<char> > Grill;
vector< vector< int> > map;

void makeMap(int h , int w) {

	Grill.resize(h);

	for (int h_ = 0; h_ < h; h_++) {

		Grill[h_].resize(w);
		for (int w_ = 0; w_ < w; w_++) {

			char input;
			cin >> input;

			Grill[h_][w_] = input;

		}
	}
}

//쓸데 없는 짓이 었다... 테트리스 처럼 푸는 줄..
/*
class Pos {
public:
	int x;
	int y;
	Pos(int y, int x) : y(y), x(x) {}
};

bool lessPos(Pos& a, Pos& b) {

	if (a.x < b.x && a.y < b.y) {
		return true;
	}
	else {
		return false;
	}
}
class Group{

public:
	int maxSize = 0;
	int max = 0;
	int group;
	vector< Pos > shape;

	Group(int group, int y, int x) : group(group) {
		shape.push_back(Pos(y, x));
	};

	void reverse() {

		int min = 999;
		for (vector<Pos>::size_type i = 0; i < shape.size(); i++) {

			if (maxSize < shape[i].x) {
				maxSize = shape[i].x;
			}
			if (maxSize < shape[i].y) {
				maxSize = shape[i].y;
			}

			if (shape[i].x > max) {
				max = shape[i].x;
			}

			if (shape[i].x < min) {
				min = shape[i].x;
			}
		}

		for (; min < max; min++, max--) {

			for (vector<Pos>::size_type i = 0; i < shape.size(); i++) {

				if (shape[i].x == min) {
					shape[i].x = max;
				}
				else if (shape[i].x == max) {
					shape[i].x = min;
				}
			}
		}
	}

	vector<Pos>& rotate(int count) {

		vector<Pos> temp = shape;

		//count 1 = 90 2 = 180 3 = 270 
		if (count >= 4) {
			rotate(count%4);
		}
		else {
			for (int i = 0; i < count; i++) {

				for (vector<Pos>::size_type j = 0; j < shape.size(); j++) {
					
					int tempx = maxSize- shape[j].y;
					int tempy = shape[j].x;
					temp.push_back(Pos(tempy, tempx));
				}
			}
		}
		sort(shape.begin(), shape.end(), lessPos);
		return temp;
	}
};

vector <Group> GroupArr;

void allReverse() {

	for (vector<Group>::size_type i = 0; i < GroupArr.size(); i++) {

		GroupArr[i].reverse();
	}
}

int check(int GroupNum) {

	for (vector<Group>::size_type j = 0; j < GroupArr.size(); j++) {

		if (GroupNum == GroupArr[j].group) {
			return j;
		}
	}

	return -1;
}

void makeGroup(int h, int w) {

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++) {

			if (GroupArr.size() == 0) {
				if (Grill[y][x] != 0) {
					GroupArr.push_back(Group(Grill[y][x], y, x));
				}
			}
			else {
				int flag = check(Grill[y][x]);
				if (Grill[y][x] != 0) {
					if (flag != -1) {
						GroupArr[flag].shape.push_back(Pos(y, x));
					}
					else {
						GroupArr.push_back(Group(Grill[y][x], y, x));
					}
				}

			}
		}
	}
}
*/
int main() {

	int TestCase;

	cin >> TestCase;

	for (int i = 0; i < TestCase; i++) {

		int h, w;
		cin >> h >> w;

		makeMap(h, w);

		int max = w - 1;
		int min = 0;

		for (; min < max; min++, max--) {

			for (int j = 0; j < h; j++) {

				char temp = Grill[j][min];
				Grill[j][min] = Grill[j][max];
				Grill[j][max] = temp;
			}
		}

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cout << Grill[y][x];
			}
			cout << endl;
		}

		Grill.clear();
	}


}