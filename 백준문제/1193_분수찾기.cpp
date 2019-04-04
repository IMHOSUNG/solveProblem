#include <iostream>
using namespace std;

int main() {

	int num;
	cin >> num;

	int temp = 0;
	int sum = 0;
	for (int i = 1;num-temp > 0; i++) {		
		temp += i;
		sum = i;
	}

	sum++;

	if (sum  % 2 != 0) {
		int up = 0;
		int down = sum ;
		for (int i = num - temp + sum - 1; i > 0; i--) {

			up++;
			down--;
		}
		cout << up << "/" << down << endl;
	}
	else{
		int up = sum;
		int down = 0;
		for (int i = num - temp + sum - 1; i > 0; i--) {

			up--;
			down++;
		}
		cout << up << "/" << down << endl;
	}
}