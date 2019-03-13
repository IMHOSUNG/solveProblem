#include <iostream>
#include <queue>
using namespace std;

queue<int> q;


int main() {

	int num, jimin, hansu;

	cin >> num >> jimin >> hansu;
	
	for (int i = 1; i <= num; i++) {

		q.push(i);
		if (num % 2 == 1) {
			q.push(-1);
		}
	}

	int round = 0;

	while (!q.empty()) {

		int temp1 = q.front();
		q.pop();
		int temp2 = q.front();
		q.pop();

		if ((temp1 == jimin && temp2 == hansu) 
			|| (temp2 == jimin && temp1 == hansu)) {
			break;
		}

		int flag = 0;
		if (temp1 == jimin || temp1 == hansu) {
			q.push(temp1);
			flag++;
		}
		if (temp2 == jimin || temp2 == hansu) {
			q.push(temp2);
			flag++;
		}

		if (flag == 0) {
			q.push(temp1);
		}

		round++;

	}

	cout << round << endl;
}