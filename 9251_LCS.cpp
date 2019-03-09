#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> arr;

int max_ = 0;

void function(string base, string comp) {

	for (int i = 0; i < base.size(); i++) {

		int count = 0;
		for (int j = 0; j < comp.size(); j++) {

			if (i + j > base.size() - 1) {
				break;
			}

			if (base[i + j] == comp[j]) {
				count++;
				if (max_ < count) {
					max_ = count;
					cout << max_ << endl;
				}
			}
			else {
				count = 0;
			}
		}
	}
}

int main() {

	string a;
	string b;
	
	cin >> a;
	cin >> b;

	int big_size = 0;
	if (a.size() >= b.size()) {
		big_size = a.size();

		function(a, b);
	}
	else {
		big_size = b.size();
		function(b, a);
	}

	cout << max_ << endl;
}