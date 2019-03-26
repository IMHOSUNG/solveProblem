#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<long> buildingArr;

double CalSlope(long center, long other) {

	double x1 = center;
	double y1 = buildingArr[center];
	double x2 = other;
	double y2 = buildingArr[other];

	double cal = (y2 - y1) / (x2 - x1);
	return cal;	
}

int main() {

	long numBuilding;

	cin >> numBuilding;

	for (long i = 0; i < numBuilding; i++) {

		long input;
		cin >> input;
		buildingArr.push_back(input);
	}

	long maxCenter = 0;
	long maxBuilding = 0;

	double curLeftSlope = 0;
	double curRightSlope = 0;
	for (long center = 0; center < buildingArr.size(); center++) {

		long tBuilding = 0;

		if (center - 1 >= 0) {
			curLeftSlope = CalSlope(center, center - 1);

			long count = 1;

			//왼쪽일 때는 음수
			for (long left = center - 1; left >= 0 && center - 1 >= 0; left--) {

				double calSlopeLeft = CalSlope(center, left);
				if (curLeftSlope > calSlopeLeft || count == 1) {
					tBuilding++;
					curLeftSlope = calSlopeLeft;
				}
				count++;
			}
		}
		if (center + 1 < buildingArr.size()) {
			curRightSlope = CalSlope(center, center + 1);

			long count = 1;

			//오른쪽 일 때는 양수
			for (long right = center + 1; right < buildingArr.size() && center + 1 < buildingArr.size(); right++) {

				double calSlopeRight = CalSlope(center, right);
				if (curRightSlope < calSlopeRight || count == 1) {
					tBuilding++;
					curRightSlope = calSlopeRight;
				}
				count++;
			}
		}

		if (tBuilding > maxBuilding) {
			maxCenter = center;
			maxBuilding = tBuilding;
		}
	}

	cout << maxBuilding << endl;
}