#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > Grill;

void makeMap(int h , int w) {

	Grill.resize(h);

	for (int h_ = 0; h_ < h; h_++) {

		Grill[h_].resize(w);
		for (int w_ = 0; w_ < w; w_++) {

			char input;
			cin >> input;
			if (input != '.')
				Grill[h_][w_] = (input - 'a' + 1);
			else
				Grill[h_][w_] = 0;
		}
	}
}

class Pos {
public:
	int x;
	int y;
	Pos(int y, int x) : y(y), x(x) {}
};

class Group{

public:
	int group;
	vector< Pos > shape;

	Group(int group, int y, int x) : group(group) {
		shape.push_back(Pos(y, x));
	};

	void reverse() {

		int max = 0;
		int min = 999;
		for (vector<Pos>::size_type i = 0; i < shape.size(); i++) {

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

	void rotate(int count) {

		if (count > 3) {
			cout << "360degree is same 0 degree" << endl;
		}
		else {

		}

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

int main() {

	int TestCase;

	cin >> TestCase;

	for (int i = 0; i < TestCase; i++) {

		int h, w;
		cin >> h >> w;

		makeMap(h, w);

		makeGroup(h, w);

		allReverse();


	}


}