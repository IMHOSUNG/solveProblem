#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	int time;
	int indegree;
	vector <int> before;
	vector <int> after;
};

vector <Node> map;
vector <int> time;
queue < int> q;

void makeMap(int num) {

	map.resize(num + 1);

	for (int i = 1; i <= num; i++) {

		for (int j = 0; ; j++) {

			int input;
			cin >> input;
			if (input == -1) {
				break;
			}
			else {

				if (j == 0) {
					map[i].time = input;
				}
				else {
					map[i].before.push_back(input);
					map[i].indegree++;
					map[input].after.push_back(i);
				}
			}
		}
	}

}

int main() {

	int num;

	cin >> num;
	time.resize(num + 1);
	makeMap(num);

	for (int i = 1; i <= num; i++) {

		if (map[i].indegree == 0)
			q.push(i);
	}

	while (!q.empty()) {

		int temp = q.front();
		q.pop();

		int sumBeforeTime = 0;

		for (int i = 0; i < map[temp].before.size(); i++) {

			sumBeforeTime = max(sumBeforeTime, time[map[temp].before[i]]);
		}

		sumBeforeTime += map[temp].time;
		time[temp] = sumBeforeTime;

		for (int i = 0; i < map[temp].after.size(); i++) {

			map[map[temp].after[i]].indegree--;

			if (map[map[temp].after[i]].indegree == 0) {
				q.push(map[temp].after[i]);
			}
		}
	}

	for (int i = 1; i < time.size(); i++) {
		cout << time[i] << endl;
	}
}