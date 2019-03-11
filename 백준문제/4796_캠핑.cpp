#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> a; 
int main() {
	
	int l, p, v;

	for (int i = 1;; i++)
	{
		cin >> l >> p >> v;
		
		if (l == 0 || p == 0 || v == 0) {
			break;
		}

		int div = v / p;
		int mod = v % p;

		if (mod == 0) {
			cout << "Case " << i << ": " << div * l << endl;
		}
		else {
			if (mod >= l) {
				cout << "Case " << i << ": " << (div * l) + l << endl;
			}
			else {
				cout << "Case " << i << ": " << (div * l) + mod << endl;
			}
		}
	}
}