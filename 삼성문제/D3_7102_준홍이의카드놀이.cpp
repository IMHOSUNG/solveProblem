#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	int num;
	int count;

	Node(int num, int count) : num(num), count(count) {}
};

bool cmp(Node& a, Node& b) {

	if (a.count >= b.count) {

		if (a.count == b.count) {

			if (a.num < b.num) {
				return true;
			}
			else {
				return false;
			}
		}
		else {

			return true;
		}

	}
	else {
		return false;
	}
}
int main() {

	int testCase;
	cin >> testCase;

	for (int i = 1; i <= testCase; i++) {

		vector<Node> arr;
		int n, m;
		cin >> n >> m;

		for (int n1 = 1; n1 <= n; n1++) {
			
			for (int m1 = 1; m1 <= m; m1++) {
				
				int sum = n1 + m1;
				int flag = 0;
				for (int k = 0; k < arr.size(); k++) {

					if (arr[k].num == sum) {
						flag = 1;
						arr[k].count++;
					}
				}

				if (flag == 0) {
					arr.push_back(Node(sum,1));
				}
			}
		}

		for (int ai = 0; ai < arr.size(); ai++) {

			for (int aj = ai; aj < arr.size(); aj++) {

				if (!cmp(arr[ai], arr[aj])) {
					swap(arr[ai], arr[aj]);
				}
			}
		}

		int maxNum = arr[0].count;
		cout << "#" << i << " " << arr[0].num;
		for (int index = 1; index < arr.size(); index++) {
			if (maxNum == arr[index].count) {
				cout << " " << arr[index].num;
			}
		}
		cout << endl;

		arr.clear();
	}
}