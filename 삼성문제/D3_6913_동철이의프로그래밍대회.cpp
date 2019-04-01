#include <iostream>
#include <vector>
using namespace std;

int main() {

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {

		int N, M;
		cin >> N >> M;

		vector< int > Rank;
		Rank.resize(N);
		int Max = 0;
		for (int n = 0; n < N; n++) {

			for (int m = 0; m < M; m++) {

				int input;
				cin >> input;

				if(input == 1)
					Rank[n]++;
			}
			if (Max < Rank[n]) {
				Max = Rank[n];
			}
		}

		int First = 0;
		for (int i = 0; i < Rank.size(); i++) {

			if (Rank[i] == Max)
			{
				First++;
			}
		}

		cout << "#" << t << " " << First << " " << Max << endl;
		Rank.clear();
	}
}