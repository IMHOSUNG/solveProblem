#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_ = 0;

class Time {
public:
	int start;
	int end;

	Time(int start, int end){
		this->start = start;
		this->end = end;
	}
};

bool end_big(const Time &a , const Time &b) {

	return a.end < b.end;
}

bool start_big(const Time &a, const Time &b) {

	return a.start < b.start;
}

vector<Time> a;
void function(int index, int count) {

	int end = a[index].start;
	count++;

	for (int j = index-1; j >= 0; j--) {
		if (a[j].end <= end) {
			function(j,count);
			break;
		}
	}

	if (max_ <= count) {
		max_ = count;
	}
}

int main() {

	int n = 0;

	cin >> n;

	int start = 0, end = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		a.push_back(Time(start, end));
	}

	sort(a.begin(), a.end(), start_big);

	for (int i = a.size() - 1; i >= a.size()-3; i--) {
		function(i,0);
	}

	cout << max_ << endl;

	return 0;
}