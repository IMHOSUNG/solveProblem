#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Answer {
public:
	string an;
	int price;

	Answer(string an, int price) : an(an), price(price) {}
};

bool check(string& in, Answer & ans) {

	for (int i = 0; i < ans.an.size(); i++) {

		if (ans.an[i] == '*' || ans.an[i] == in[i]) {
			continue;
		}
		else {

			return false;
		}	
	}
	return true;
}

int main() {

	int testCase; 
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {

		int n, m;
		cin >> n >> m;

		vector<Answer> ans;
		for (int i = 0; i < n; i++) {
			string input;
			int price;

			cin >> input >> price;

			ans.push_back(Answer(input, price));
		}

		int getMoney = 0;

		for (int i = 0; i < m; i++) {

			string in;
			cin >> in;

			for (int j = 0; j < ans.size(); j++) {

				if (check(in,ans[j])) {
					getMoney += ans[j].price;
				}
			}
		}

		cout << "#" << t << " " << getMoney << endl;
		ans.clear();
	}
}