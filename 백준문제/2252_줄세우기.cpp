#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector < vector < int > > map;
deque < int > queue;

int main(){

	int student_num;
	int student_case;

	cin >> student_num >> student_case;

	map.resize(student_num + 1);
	for (int i = 0; i < map.size(); i++) {
		map[i].resize(1);
	}

	for (int i = 0; i < student_case; i++) {

		int front, end;
		cin >> front >> end;
		map[end][0]++;
		map[front].push_back(end);		
	}

	//start 하는 점 대기 큐에 넣어주기
	for (int i = 1; i < map.size(); i++) {

		if (map[i][0] == 0) {
			queue.push_back(i);
		}
	}

	//위상 정렬 시작

	while (!queue.empty()) {

		int temp = queue.front();
		cout << temp << " ";
		queue.pop_front();
		
		for (int i = 1; i < map[temp].size(); i++) {
			map[map[temp][i]][0]--;
			if (map[map[temp][i]][0] == 0) {
				queue.push_back(map[temp][i]);
			}
		}
	}
}