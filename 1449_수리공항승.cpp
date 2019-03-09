#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int n, l;
	cin >> n >> l;

	vector<int> a;

	for (int i = 0; i < n; i++) {
		
		int input;
		cin >> input;
		a.push_back(input);
	}

	sort(a.begin(), a.end());

	int loop = a.size() - 1;

	int count = 0;
	while (loop >= 0) {

		int start = a[loop];
		int end = a[loop] - (l - 1);
		count++;

		if (end <= a[0]) {
			break;
		}

		for (int i = loop; i >= 0; i--) {
			if (a[i] < end) {
				loop = i;
				break;
			}
		}
	}

	cout << count << endl;
}