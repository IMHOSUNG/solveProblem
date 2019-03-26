//수열의 합
// 풀이 
// 찾는 수 = A
// A  = (x) + (x+1)..... + (x+ k-1)
// A = x*k + (1 + 2 + .... +k-1)
// A = x*k + (k)*(k-1)/2
// 시작하는 x 수를 찾아내면 됨
// x*k = - (k)*(k-1)/2 + A 
// x = (A - (k)*(k-1)/2)/k 

#include <iostream>
using namespace std;

int main() {

	int A, k;

	cin >> A >> k;

	int check = 0;
	int x = 0;

	for (int i = k; i <= 100; i++) {

		if ((A - ((i)*(i - 1)) / 2) % i == 0 && (A - ((i)*(i - 1)) / 2)/i >= 0) {

			x = (A - ((i)*(i - 1)) / 2)/i;
			check = 1;
			break;
		}
	}

	if (check == 0) {
		cout << -1 << endl;
	}
	else {
		int sum= 0;
		for (int i = x;; i++) {

			if (sum == A) {
				break;
			}

			sum += i;
			cout << i << " ";
		}
		cout << endl;
	}


}