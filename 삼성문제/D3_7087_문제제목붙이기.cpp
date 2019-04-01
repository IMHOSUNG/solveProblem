#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {

		int numString;
		cin >> numString;
		vector <int> arr;
		arr.resize(30);
		string a;
		for (int i = 0; i < numString; i++) {

			cin >> a;
			arr[(int)((char)a[0] - ('A'))]++;
 		}

		int Max = 0;
		for (int i = 0; i < arr.size(); i++) {

			if (arr[i] == 0) {
				break;
			}	
			Max++;
		}

		cout <<"#"<<t << " " <<  Max << endl;

		Max = 0;
		a.clear();
		arr.clear();
	}
}