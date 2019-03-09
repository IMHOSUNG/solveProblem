#include <iostream>
#include <vector>
using namespace std;

vector<int> queue;
vector<int> answer;

int breakfunction() {
	for (int j = 0; j < queue.size(); j++) {

		if (queue[j] != 0) {
			return 0;
		}
	}

	return 1;
}

int main() {

	int num, find;
	cin >> num >> find;

	for (int i = 1; i <= num; i++) {
		queue.push_back(i);
	}

	int index = find-1;

	for (;;) {
		answer.push_back(queue[index]);
		queue[index] = 0;

		if (breakfunction()) {
			break;
		}
		int count = 0;
		for (int i = index+1;; i++) {
			if (i > num - 1) {
				i = i % num;
			}

			if (queue[i] != 0) {
				count++;
			}

			if (count == find) {
				index = i;
				break;
			}
		}
	}

	cout << '<';
	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << ", ";
	}
	cout << answer[answer.size() - 1] << '>' << endl;
}