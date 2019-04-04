#include <iostream>
using namespace std;

int main() {

	unsigned long long n;
	cin >> n;

	unsigned long long a = 0;
	unsigned long long b = 1;

	unsigned long long c = 0;
	if (n == 1) {
		c = 1;
	}
	for (int i = 2; i <= n ; i++) {

		c = a + b;
		a = b;
		b = c;
	}

	cout << c << endl;
}