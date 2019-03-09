#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Node {
public:
	int com_num;
	int check;
	
	Node(int com_num, int check) : com_num(com_num), check(check) {}
};

vector < vector<Node> > map;
deque < Node > queue;
vector < int > check;

int isChecked(Node& in) {
	
	if (check[in.com_num] == 1)
		return 1;
	else
		return 0;
}

void bfs() {

	while (!queue.empty()) {

		Node temp = queue.front();
		queue.pop_front();

		check[temp.com_num] = 1;
		for (int i = 0; i < map[temp.com_num].size(); i++) {

			if (!isChecked(map[temp.com_num][i])) {
				queue.push_back(map[temp.com_num][i]);
			}
		}
	}

	int count = 0;
	for (int i = 2; i < check.size(); i++) {
		
		if (check[i] == 1)
			count++;
	}

	cout << count << endl;
}

int main() {

	int com_num;
	int relation;
	int x, y;

	cin >> com_num;
	cin >> relation;

	//¸Ê »ý¼º ¿Ï·á
	map.resize(com_num + 1);
	check.resize(com_num + 1);
	for (int i = 0; i < relation; i++) {
		
		cin >> x >> y;

		map[x].push_back(Node(y, 0));
		map[y].push_back(Node(x, 0));
	}

	check[1] = 1;
	for (int i = 0; i < map[1].size(); i++) {
		queue.push_back(map[1][i]);
	}

	bfs();

}