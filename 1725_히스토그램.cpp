#include <iostream>
#include <vector>
using namespace std;

vector<int> his;
int max_ = 0;

void function() {

	int current_width = 1;
	for (int current = 0; current < his.size()-1 ; current++) {
		
		if (his[current] > his[current + 1]) {
			
			int area = current_width * his[current];
			cout << current_width << endl;
			if (area < (current_width + 1)*his[current + 1]) {
				max_ = (current_width + 1) * his[current + 1];
				current_width++;
			}
			else {
				if (max_ < area)
				{
					max_ = area;
				}
			}
		}
		else if (his[current] <= his[current + 1]) {
			
			int area = (current_width+1) * his[current];

			if (area <= his[current + 1]) {
				max_ = his[current + 1];
				current_width = 1;
			}
			else {
				max_ = area;
				current_width++;
			}
		}

	}
}

int main() {
	
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		int input;
		cin >> input;

		his.push_back(input);
	}

	function();

	
	if (max_ > num)
		cout << max_ << endl;
	else
		cout << num << endl;
}