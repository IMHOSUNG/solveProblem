#include <iostream>
#include <vector>
using namespace std;

int maxCatchFish = 0;

class Pos {
public:
	int s_x;
	int s_y;

	Pos(int s_x, int s_y) 
		: s_x(s_x), s_y(s_y){}
};

vector<Pos> fishPoint;

int main() {

	int n, i, m;
	cin >> n >> i >> m;
	
	for (int fish = 0; fish < m; fish++) {
		int x, y;
		cin >> y >> x;
		fishPoint.push_back(Pos(x, y));
	}

	//make net
	//그물 총 길이 4 ~ 100
	//물고기 범위가 1 ~ 100
	// 시간 복잡도는 100*100*100

	for (int f = 0; f < fishPoint.size(); f++) {

		for (int w = 1; w < i / 2; w++) {


			int h = (i / 2) - w;

			for (int x = fishPoint[f].s_x - w; x <= fishPoint[f].s_x; x++) {

				for (int y = fishPoint[f].s_y - h; y <= fishPoint[f].s_y; y++) {
					
					int curCatchFish = 0;
					for (int i = 0; i < fishPoint.size(); i++) {

						if (fishPoint[i].s_x >= x && fishPoint[i].s_x <= x + w) {
							
							if (fishPoint[i].s_y >= y && fishPoint[i].s_y <= y + h) {
								curCatchFish++;
							}
						}
					}
					if (curCatchFish > maxCatchFish) {
						maxCatchFish = curCatchFish;
					}
				}
			}
			
				

			
		}
	}

	cout << maxCatchFish << endl;
}