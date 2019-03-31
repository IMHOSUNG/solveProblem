#include <iostream>
#include <string>
using namespace std;

int main() {

	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++)
	{
		int n;
		string input;
		cin >> n >> input;

		int sum = 0;
		for (int i = 0; i < input.size(); i++) {

			sum += input[i] - '0';

		}
		cout << "#"<< t << " " <<sum % (n - 1) << endl;
	}
}