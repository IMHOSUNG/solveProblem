#include <iostream>
#include <deque>
#include <queue>
using namespace std;

deque <int> m;
queue <int> f;

int main() {

	int queueSize, extractNum;
	cin >> queueSize >> extractNum;

	for (int i = 1; i <= queueSize; i++) {
		m.push_back(i);
	}

	for (int i = 0; i < extractNum; i++) {
		int input;
		cin >> input;
		f.push(input);
	}

	int Count = 0;
	while (!f.empty()) {

		//왼쪽으로 돌리는 게 유용한 지
		//오른쪽으로 돌리는 게 유용한지 찾고
		int cur = f.front();
		f.pop();

		int index = 0;
		for (int i = 0; i < m.size(); i++) {

			if (cur == m[i]) {
				index = i;
				break;
			}
		}

		if ((m.size() - 1 - index) >= index ) {
			//왼쪽으로
			for (int i = 0;; i++) {
				if (m[0] == cur) {
					m.pop_front();
					break;
				}
				int temp = m.front();
				m.pop_front();
				m.push_back(temp);
				Count++;
			}
		}
		else {
			for (int i = (m.size()-1);; i--) {
				if (m[0] == cur) {
					m.pop_front();
					break;
				}
				int temp = m.back();
				m.pop_back();
				m.push_front(temp);
				Count++;
			}
		}
	}

	cout << Count << endl;
}