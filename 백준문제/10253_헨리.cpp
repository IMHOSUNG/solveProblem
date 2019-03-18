#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> arr;

void function(int a, int b) {

	
	if (a == 0 || b == 0) {
		return;
	}
	else
	{
		int temp1 = a;
		int temp2 = b;

		int x = (int)ceil((double)b / (double)a);

		arr.push_back(x);

		temp1 = a * x - b;
		temp2 = b * x;

		function(temp1, temp2);
	}
}

int main() {

	int TestCase;
	cin >> TestCase;

	for (int i = 0; i < TestCase; i++) {

		int a, b;
		cin >> a >> b;

		function(a, b);

		cout << arr[arr.size() - 1] << endl;
		arr.clear();
	}
}