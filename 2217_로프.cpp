#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
int main() {
	int n = 0;
	int input = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}

	sort(a.begin(), a.end());

	int max = 0;

	for (int i = 0; i < a.size(); i++) {
		
		int temp = (a[i] * (a.size() - i));
		if (max < temp)
		{
			max = temp;
		}
	}


	cout << max << endl;
	return 0;
}