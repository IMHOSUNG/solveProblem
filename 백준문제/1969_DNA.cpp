#include <iostream>
#include <vector>
using namespace std;

char map[2000][2000];
vector<int> a;
vector<char> answer;
int main() {

	int n, m;

	cin >> n >> m;

	a.resize(4);

	int distance = 0;

	for (int i = 0; i < n; i++) {
		char input;
		for (int j = 0; j < m; j++) {

			cin >> input;
			map[i][j] = input;
		}
	}

	for (int i = 0; i < m; i++) {
		a.resize(4);
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 'A') {
				a[0]++;
			}
			else if (map[j][i] == 'C') {
				a[1]++;
			}
			else if (map[j][i] == 'G') {
				a[2]++;
			}
			else if (map[j][i] == 'T') {
				a[3]++;
			}
		}

		int max = 0;
		int sum = 0;
		int index = 0;
		for (int s = 0; s < a.size(); s++) {
			
			if (max < a[s]) {
				max = a[s];
				index = s;
			}
			sum += a[s];
		}

		distance += (sum - max);
		
		if (index == 0)
		{
			answer.push_back('A');
		}if (index == 1)
		{
			answer.push_back('C');
		}if (index == 2)
		{
			answer.push_back('G');
		}if (index == 3)
		{
			answer.push_back('T');
		}
		a.clear();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
	cout << endl;
	cout << distance << endl;
}