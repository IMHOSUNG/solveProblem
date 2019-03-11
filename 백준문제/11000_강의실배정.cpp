#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Room {
public:
	int start;
	int end;
	int time;

	Room(int start, int end) {
		this->start = start;
		this->end = end;
		this->time = end - start;
	}
};

vector<Room> a;

bool startSort(const Room &a, const Room &b) {
	return a.end < b.end;
}

int main() {
	
	int n = 0;
	cin >> n;

	int start, end = 0;
	for (int i = 0; i < n; i++) {
		
		cin >> start >> end;

		a.push_back(Room(start, end));
	}

	sort(a.begin(), a.end(), startSort);

	int max = 0;
	int count = 1;

	for (int i = 0; i < a.size(); i++) {

		int s = a[i].start;
		int e = a[i].end;
	}

	cout << max << endl;
	
}