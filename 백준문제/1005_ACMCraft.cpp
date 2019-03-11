#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Node {
public:
	int indegree = 0;
	int time = 0;
	vector<int> before;
	vector<int> after;
};

vector<Node> map;
vector<int> constTime;
queue<int> q;

int main() {

	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {

		int BulidCount, RuleCount;
		cin >> BulidCount >> RuleCount;
		
		map.resize(BulidCount+1);
		constTime.resize(BulidCount + 1);

		for (int a = 1; a <= BulidCount; a++) {

			int time = 0;
			cin >> time;
			map[a].time = time;
			constTime[a] = time;
		}

		for (int j = 1; j <= RuleCount; j++) {

			int before, after;
			cin >> before >> after;

			map[after].before.push_back(before);
			map[before].after.push_back(after);
			map[after].indegree++;
		}

		int answer = 0;
		cin >> answer;
		// ���� ���� �� ���� �Ϸ�

		for (int k = 1; k <= BulidCount; k++) {
			if (map[k].indegree == 0) {
				q.push(k);
			}
		}

		while (!q.empty()) {

			int current = q.front();
			q.pop();

			int Time = 0;

			//�ڽſ��� ������ ���� Ž���Ͽ� �ְ� �ð��� ã��
			for (int x = 0; x < map[current].before.size(); x++) {
				Time = max(Time, constTime[map[current].before[x]]);
			}

			//�ڽ��� ���� �ð��� ���� ������
			Time += map[current].time;
			//�� �ð��� �־��ش�.
			constTime[current] = Time;

			for (int y = 0; y < map[current].after.size(); y++) {

				map[map[current].after[y]].indegree--;
				if (map[map[current].after[y]].indegree == 0) {
					q.push(map[current].after[y]);
				}
			}

			
		}

		cout << constTime[answer] << endl;
		map.clear();
		constTime.clear();
	}
}