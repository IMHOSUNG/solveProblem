#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> fib;

int main() {

	int num = 0;
	cin >> num;

	fib.resize(2);
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i <= num; i++) {
		fib.push_back( (int)((fib[i - 2] + fib[i - 1]) % 15746));
	}

	cout << fib[num] << endl;
}