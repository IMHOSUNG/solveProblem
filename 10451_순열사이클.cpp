#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector <int> map;
vector <int> check;
deque <int> queue;


void bfs(int num) {

	int count = 0;

	check.resize(num + 1);
	for (int i = 1; i <= num; i++){
		
		check.resize(num + 1);
		//스타트 지점 설정
		int start = i;
		check[start] = 1;
		queue.push_back(map[i]);

		while (!queue.empty()) {

			int temp = queue.front();
			queue.pop_front();

			if (temp == start) {
				count++;
			}
			else {

				if (check[temp] == 0) {
					check[temp] = 1;
					queue.push_back(map[temp]);
				}
			}
		}
	}
	cout << count << endl;
	count = 0;
	check.clear();
}

int main() {

	int loop = 0;

	cin >> loop;

	for (int i = 0; i < loop; i++) {

		int num = 0;
		cin >> num;

		//인덱스와 맞추기 위해서
		//맵과 체크 하는 배열 생성
		map.resize(num + 1);
		for (int j = 1; j <= num; j++) {

			int input = 0;
			cin >> input;

			map[j] = input;
		}

		bfs(num);

		map.clear();
	}
}