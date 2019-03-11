#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Homework {
public:
	int mazino;
	int score;
	int check = 0;

	Homework(int time, int score) {
		this->mazino = time;
		this->score = score;
	}
};

bool sort_function(const Homework & a, const Homework & b) {

	return a.score > b.score;
}

vector<Homework> map;

int main() {

	int n;
	cin >> n;
	int max = 0;

	for (int i = 0; i < n; i++) {

		int a, b;
		cin >> a >> b;
		if (max < b) {
			max = b;
		}
		map.push_back(Homework(a, b));
	}

	sort(map.begin(), map.end(), sort_function);
	
	int all = 0;
	for (vector<Homework>::size_type i = max; i >= 1; i--)
	{
		for (vector<Homework>::size_type j = 0; j < map.size(); j++) {

			if (map[j].check == 0 && map[j].mazino >= i) {
				all += map[j].score;
				//cout << map[j].score << endl;
				map[j].check = 1;
				break;
			}
		}
	}

	cout << all << endl;
}