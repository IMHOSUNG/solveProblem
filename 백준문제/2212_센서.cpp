#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input;
vector<int> d;

bool sort_function(const int & a, const int & b) {
	return a > b;
}
int main() {

	int n, m;

	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {

		int in;
		cin >> in;
		input.push_back(in);
	}

	sort(input.begin(), input.end());

	for (int i = 1; i < input.size(); i++) {

		int temp = (input[i] - input[i - 1]);
		d.push_back(temp);
	}

	sort(d.begin(), d.end(), sort_function);

	int sum = 0;

	for (int i = m - 1; i < d.size(); i++) {
		sum += d[i];
	}

	cout << sum << endl;
}