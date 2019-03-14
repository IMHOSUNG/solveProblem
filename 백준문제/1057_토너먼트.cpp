#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector < queue<int> > t;

int function(queue<int> temp, int i, int jimin, int hansu) {
	while (true) {

		if (t[i].size() == 0) {
			t.push_back(temp);
			return 1;
		}
		else if (t[i].size() == 1) {

			int temp1 = t[i].front();
			t[i].pop();
			temp.push(temp1);
		}
		else {
			int temp1 = t[i].front();
			t[i].pop();
			int temp2 = t[i].front();
			t[i].pop();

			if ((temp1 == jimin && temp2 == hansu) || (temp2 == jimin && temp1 == hansu)) {
				return 0;
			}
			else if ((temp1 == jimin || temp1 == hansu)) {
				temp.push(temp1);
			}
			else if ((temp2 == jimin || temp2 == hansu)) {
				temp.push(temp2);
			}
			else {
				temp.push(temp1);
			}

		}
	}
}
int main() {
	int num, jimin, hansu;
	cin >> num >> jimin >> hansu;
	t.resize(1);
	queue<int> a;
	for (int i = 1; i <= num; i++) {
		a.push(i);
	}

	t.push_back(a);

	for (int i = 1; i < t.size(); i++) {

		queue<int> temp;

		int flag = function(temp, i, jimin, hansu);

		if (flag == 0) {
			cout << i << endl;
			break;
		}
	}
}