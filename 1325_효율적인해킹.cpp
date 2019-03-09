#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector < vector <int> > map;
deque < int > queue;
vector< int > answer;
vector< int > check_arr;

int max_ = 0;

void bfs(int n) {

	int count = 1;

	answer.resize(n + 1);

	for (int i = 1; i <= n; i++) {

		check_arr.resize(n + 1);
		//���� ��ǻ�� check
		check_arr[i] = 1;

		for (int a = 0; a < map[i].size(); a++) {

			//���� ��ǻ�Ϳ� ����Ǿ� �ִ� �� check
			check_arr[map[i][a]] = 1;
			//�׸��� queue�� ����
			queue.push_back(map[i][a]);
			count++;
		}

		//���� ���� ����� ��ǻ�� Ž��
		while (!queue.empty()) {

			//���� ť�� �� �ִ� �� üũ
			int temp = queue.front();
			queue.pop_front();

			//�� �ε����� �ִ� ���� �ʿ��� ã�Ƽ� ���ο� ���� �߰ߵǸ� �ٽ�
			//ť�� ����
			for (int b = 0; b < map[temp].size(); b++) {
				//���� üũ�� �Ǿ� ���� �ʴ� ��ǻ�͸� üũ �ϰ� 
				//ť�� �ٽ� �־���
				if (check_arr[map[temp][b]] == 0) {
					
					check_arr[map[temp][b]] = 1;
					queue.push_back(map[temp][b]);
					count++;
				}
			}
		}
		answer[i] = count;

		if (count > max_) {
			max_ = count;
		}

		count = 1;
		check_arr.clear();
	}
}

int main() {

	int n, m;
	cin >> n >> m;

	map.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		//map[a].push_back(b);
		map[b].push_back(a);
	}

	bfs(n);

	for (int i = 1; i < answer.size(); i++) {

		if (max_ == answer[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}