#include <iostream>
#include <vector>
using namespace std;

int Fun(int x1, int y1, int x2, int y2, int x, int y) {

	// x1, x2 ,y1, y2 Á¤·Ä
	if (x1 < x && x < x2 && y1 < y && y < y2) {
		return 0;
	}
	else if (x1 > x || x > x2 || y1 > y || y > y2) {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {

		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int p;
		cin >> p;

		int in = 0;
		int same = 0;
		int out = 0;

		for (int n = 0; n < p; n++) {

			int x, y;
			cin >> x >> y;

			int flag = Fun(x1, y1, x2, y2, x, y);



			if (flag == 0) {
				in++;
			}
			else if (flag == 1) {
				same++;
			}
			else {
				out++;
			}

		
				 
		}
		cout << "#" << t << " " << in << " " << same << " " << out << endl;
	}
}