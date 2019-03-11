#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;

//그래프의 연결
/*
반례 테스트
2
4
0 0 1
0 1 1
1 0 1
10 0 1
2
0 0 10
0 0 1

답
2
1

2
2
0 0 1
1 0 1
3
0 0 1
2 0 1
10 0 5

답
1
2

반례
정답
1

1
4
0 0 1
0 4 1
0 1 1
0 3 1
*/
//관계를 2번 
//1번 >> 거리로 근처에 있는 것만 담아서 맵을 만들고
//2번 >> 그 맵을 통한 BFS 탐색
//트리로 푸는 방법도 있다니 그 방법으로도 풀어볼 것

class Position {
public:
	int index;
	int x;
	int y;
	int r;
	int group;

	Position(int index, int y, int x, int r) :index(index), y(y), x(x),r(r), group(0) {}
};
vector < Position > firstMap;
vector < vector < Position > > secondMap;
deque < Position > queue;
vector < int > check;
int checkDistance(int findex, int sindex) {

	int x1 = firstMap[findex].x;
	int y1 = firstMap[findex].y;
	int r1 = firstMap[findex].r;

	int x2 = firstMap[sindex].x;
	int y2 = firstMap[sindex].y;
	int r2 = firstMap[sindex].r;
	// 0 0 2
	// 0 1 3
	if ((((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2))) <= ((r1+r2)*(r1+r2)))
		return 1;
	else
		return 0;
}


void bfs(int num) {

	//make_secondMap
	secondMap.resize(num);
	for (int i = 0; i < firstMap.size(); i++) {

		for (int j = 0; j < firstMap.size(); j++) {

			if (checkDistance(i, j) == 1 && i != j) {
				secondMap[i].push_back(firstMap[j]);
			}
		}
	}
	check.resize(num);
	int group_count = 0;
	for (int i = 0; i < num; i++) {
		
		//데이터 큐에 삽입
		if (check[i] == 0)
		{
			group_count++;
			check[i] = 1;
			for (int j = 0; j < secondMap[i].size(); j++) {

				if (check[secondMap[i][j].index] == 0) {
					check[secondMap[i][j].index] = 1;
					secondMap[i][j].group = group_count;
					queue.push_back(secondMap[i][j]);
				}
			}

			while (!queue.empty()) {

				Position temp = queue.front();
				queue.pop_front();


				for (int k = 0; k < secondMap[temp.index].size(); k++) {

					if (check[secondMap[temp.index][k].index] == 0) {
						check[secondMap[temp.index][k].index] = 1;
						secondMap[temp.index][k].group = group_count;
						queue.push_back(secondMap[temp.index][k]);
					}
				}
			}
		}
	}
	cout << group_count << endl;
	check.clear();
}


int main() {

	int loop;

	cin >> loop;

	for (int i = 0; i < loop; i++) {
		
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int x, y, r;

			cin >> x >> y >> r;
			firstMap.push_back(Position(j, y, x, r));
		}

		bfs(num);

		firstMap.clear();
		secondMap.clear();
	}

}