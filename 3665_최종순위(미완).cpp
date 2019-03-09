#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Ǯ Ŀ��Ƽ�� ���� ������ ������ ����� IN OUT
//RANK ID INDEGREE V.IN V.OUT ���� Ŭ���� ����
//�Է� ������ IN�� OUT�� 

class Node {
public:
	int rank = 0;
	int indegree = 0;
	vector<int> in;
	vector<int> out;
};

vector<Node> map;

int returnValueIndex(Node a , int num , int flag) {

	//in
	if (flag == 0) {

		for (int i = 0; i < a.in.size(); i++) {

			if (num == a.in[i]) {
				return i;
			}
		}
	}
	//out
	else {

		for (int i = 0; i < a.out.size(); i++) {

			if (num == a.out[i]) {
				return i;
			}
		}
	}
}


//ó�� �ڷᱸ�� ���� �Ű� �Ἥ ���� ��
void InsertAndDelete(int front, int back) {

	int index1 = returnValueIndex(map[back],front,1);
	int index2 = returnValueIndex(map[front], back, 0);

	map[back].in.push_back(front);
	map[back].indegree++;

	map[front].out.push_back(back);

	auto iter1 = map[back].out.begin();
	auto iter2 = map[front].in.begin();

	map[back].in.erase(iter1 + index1);
	map[front].out.erase(iter2 + index2);
}

int main() {

	int num = 0;
	cin >> num;

	for (int start = 0; start < num; start++) {

		int input;
		cin >> input;

		map.resize(input + 1);
		for (int i = 1; i <= input; i++) {
			
			int input;
			cin >> input;
			map[input].rank = i;
		}
	}
}