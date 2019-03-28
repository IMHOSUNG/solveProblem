//중복 제거 하기..
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


long long dis = 90000000000;


class Pos {
public:
	long x;
	long y;
	long visited ;
	Pos(long x,long y):x(x), y(y), visited(0) {}
};

long long CalDistance(long long v_x, long long v_y) {

	return ((v_x)*(v_x))+((v_y)*(v_y));
}

long CheckAllVisited(vector<Pos> arr) {

	for (long i = 0; i < arr.size(); i++) {
	
		if (arr[i].visited == 0) {
			return 0;
		}
	}
	return 1;
}

void function(vector<Pos> temp, long s, long x, long y, long long v_x, long long v_y) {
	
	temp[s].visited = 1;	
	long long t_v_x = v_x;
	long long t_v_y = v_y;
	for (long i = s+1; i < temp.size(); i++) {
		if (temp[i].visited == 0) {
			t_v_x = x - temp[i].x;
			t_v_y = y - temp[i].y;
			temp[i].visited = 1;

			for (long j = i+1; j < temp.size(); j++) {
				if (temp[j].visited == 0) {
					function(temp, j, temp[j].x, temp[j].y, v_x, v_y);
				}
			}
		}
	}
	if (CheckAllVisited(temp) == 1) {
		
		long long temp = CalDistance(t_v_x, t_v_y);
		//cout << temp << endl;
		//cout << dis << endl;
		if (temp <= dis) {
			dis = temp;
		}
		return;
	}
}


int main() {

	long testCase;

	cin >> testCase;
	for (long i = 1; i <= testCase; i++) {

		long numBug = 0;
		cin >> numBug;
		vector<Pos> bugArr;
		//입력
		for (long j = 0; j < numBug; j++) {
			long x, y;
			cin >> x >> y;
			bugArr.push_back(Pos(x, y));
		}

		//함수
		//BFS >> 최대 시간 복잡도 20!.
		for (vector<Pos>::size_type s = 0; s < bugArr.size(); s++) {

			vector<Pos> temp = bugArr;
			
			function(temp, s, temp[s].x, temp[s].y, 0, 0);
		}
		
		cout << "#"<<i << " " << dis << endl;
		//출력 및 초기화
		dis = 900000000000;
		bugArr.clear();
	}
}

/*

1
4
6 0
3 3
-7 2
-4 -1

1
2
-100000 100000
100000 -100000
*/