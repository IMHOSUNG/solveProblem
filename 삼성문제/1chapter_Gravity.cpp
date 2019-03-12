#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> map;

int main() {

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {

		int maxValue = 0;

		int width, height;

		cin >> width >> height;

		map.resize(height);
		for (int in = 0; in < height; in++) {
			map[in].resize(width);
		}

		for (int j = 0; j < width; j++) {

			int box;
			cin >> box;
			
			for (int k = 0; k < box; k++) {
				map[k][j] = 1;
			}
		}

		for (int y = 0; y < height; y++) {
			for (int x = width - 1; x >= 0; x--) {
				if (map[y][x] == 1) {
					int diff= 0;
					for (int f = x+1; f < width; f++) {
						if (map[y][f] == 0) {
							diff++;
						}
						else {
							map[y][f] = map[y][x]+diff;
							if (maxValue < map[y][f]) {
								maxValue = map[y][f];
							}
							break;
						}
							
					}
				}
			}
		}

		cout << maxValue << endl;
	}


}