#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(),greater<int> ());

	int size = citations.size() - 1;

	if (size % 2 == 0) {
		answer = citations[size / 2];
	}
	else {
		answer = citations[size / 2 + 1];
	}

	return answer;
}

int main() {

	int N = 0;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {

		int input = 0;
		cin >> input;
		arr.push_back(input);
	}

	cout << solution(arr) << endl;
}