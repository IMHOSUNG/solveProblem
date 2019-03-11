#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ó�� ����
// ���� ������ ����ϱ� ���ؼ� ��ü�� ������� ���� �ϰ� (Ǯ Ŀ��Ʈ)
// �� �� ���� Ǯ�� ���� ������ ������ ������ ����
// �� �Ŀ� �տ� ���� ���� ������� ���������� �ϸ鼭 ã�ƺ���
// ����Ŭ�̳� �̻��� �߻��ϸ� �ѱ�
// ���� �� ������ �����ϰ� ���� ���

// ��� ����
// Ǯ Ŀ��Ʈ�� �� ��쿡��
// ���� �߻� >> 1�� ���� ������ �����ϱ� ������ �ٸ� ���� ����
// �տ��� �˻��ϴ� �� ������ ���� ������ �켱������ ã�� �� ����
// �׸��� ť�� ���� ���� ������ �Ǿ�� �ϴ� ������ �ִ�.
// ť�� ���� ���� ���������ν� ���� �������� ��� ��
// ���� ���� �켱������ �־��� �� �ִ�.

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

	//���� ���� ����
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