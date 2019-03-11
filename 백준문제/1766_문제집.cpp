#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 처음 생각
// 순서 정보를 기억하기 위해서 전체를 순서대로 연결 하고 (풀 커넥트)
// 그 중 먼저 풀면 좋은 문제는 역으로 순서를 연결
// 이 후에 앞에 문제 부터 순서대로 위상정렬을 하면서 찾아보고
// 사이클이나 이상이 발생하면 넘김
// 만들 수 있으면 정지하고 답을 출력

// 계속 생각
// 풀 커넥트를 할 경우에는
// 문제 발생 >> 1번 부터 실행이 가능하기 때문에 다른 조건 무시
// 앞에서 검색하는 것 만으로 앞의 문제의 우선순위를 찾을 수 있음
// 그리고 큐에 들어가는 값이 정렬이 되어야 하는 문제가 있다.
// 큐에 들어가는 값을 정렬함으로써 여러 방향으로 뻗어갈 때
// 작은 값을 우선적으로 넣어줄 수 있다.

class Node {
public:
	int indegree;
	vector<int> in;
	vector<int> out;
};

vector<Node> m;
priority_queue<int, vector<int> ,greater<int>> q;
vector<int> answer;

int main() {

	int NumProblem, CountRule;

	cin >> NumProblem >> CountRule;

	m.resize(NumProblem + 1);

	for (int i = 0; i < CountRule; i++) {
		int first, second;

		cin >> first >> second;
		m[first].out.push_back(second);
		m[second].in.push_back(first);
		m[second].indegree++;
	}

	//위상 정렬 시작
	for (int i = 1; i <= NumProblem; i++) {

		if (m[i].indegree == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {

		int size = 0;
		int cur = q.top();
		q.pop();
		answer.push_back(cur);

		for (int i = 0; i < m[cur].out.size(); i++) {

			m[m[cur].out[i]].indegree--;
			if (m[m[cur].out[i]].indegree == 0) {
				q.push(m[cur].out[i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}