#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	vector<int> in;
	vector<int> out;
	int indgree;
};

vector< Node> m;
vector< int > Rank;
queue<int> q;
vector <int > answer;
void makeMap(int numTeam) {

	for (int i = 1; i <= numTeam; i++) {

		for (int j = i+1; j <= numTeam; j++) {

			m[Rank[i]].out.push_back(Rank[j]);
			m[Rank[j]].in.push_back(Rank[i]);
			m[Rank[j]].indgree++;
		}
	}
}

void changeMap(int before, int after) {

	int flag = 0;
	for (int i = 0; i < m[before].in.size(); i++) {

		if (m[before].in[i] == after) {
			m[before].indgree--;
			m[before].in.erase(m[before].in.begin() + i);
			break;
		}

		if (i == m[before].in.size() - 1) {
			flag++;
			m[before].indgree++;
		}
	}

	for (int i = 0; i < m[after].out.size(); i++) {

		if (m[after].out[i] == before) {
			m[after].out.erase(m[after].out.begin() + i);
			break;
		}

		if (i == m[after].out.size() - 1) {
			flag++;
			m[after].indgree++;
		}
	}

	if (flag < 2)
	{
		m[before].out.push_back(after);
		m[after].in.push_back(before);
		m[after].indgree++;
	}
}

int function(int numTeam) {

	for(int i = 1; i <= numTeam ; i++) {
		
		if (q.empty()) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		else if (q.size() > 1) {
			cout << "?" << endl;
			return 0;
		}

		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for (int x = 0; x < m[cur].out.size(); x++) {

			m[m[cur].out[x]].indgree--;
			if (m[m[cur].out[x]].indgree == 0) {
					q.push(m[cur].out[x]);
			}
		}
	}

	return 1;
}

int main() {

	int testCase;
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {

		int numTeam;
		cin >> numTeam;
		Rank.resize(numTeam+1);
		m.resize(numTeam + 1);

		for (int j = 1; j <= numTeam; j++) {

			int teamId;
			cin >> teamId;

			Rank[j] = teamId;
		}

		makeMap(numTeam);

		int numRule;
		cin >> numRule;

		for (int k = 1; k <= numRule; k++) {

			int before, after;
			cin >> before >> after;
			changeMap(before, after);
		}
		//¸Ê »ý¼º ¿Ï·á

		for (int a = 1; a <= numTeam; a++) {

			if (m[Rank[a]].indgree == 0) {
				q.push(Rank[a]);
			}
		}

		if (function(numTeam)) {

			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << " ";
			}
			cout << endl;
		}

		answer.clear();
		m.clear();
		Rank.clear();
	}
}
