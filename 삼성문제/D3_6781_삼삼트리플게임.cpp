#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//count 정렬 사용
//만들 경우의 수 중 max 값 뽑아내서 그 케이스가 3개면 통과

class Node {
public:
	char num;
	char color;
	int count;
	
	Node(char num, char color, int count) : num(num), color(color), count(count) {}
};

bool cmp(Node& a, Node& b) {

	if (a.color < b.color) {
		return true;
	}
	else {
		return false;
	}
}

bool cmp2(Node& a, Node& b) {
	if (a.num < b.num) {
		return true;
	}
	else {
		return false;
	}
}

bool check(char num, char color, vector<Node>& arr) {

	for (int i = 0; i < arr.size(); i++) {

		if (arr[i].color == color && arr[i].num == num) {
			arr[i].count++;
			return true;
		}
	}

	return false;
}

int FindThree(vector<Node> & color) {

	int threeCount = 0;
	for (int i = 0; i < color.size(); i++) {
		if (color[i].count >= 3) {
			color[i].count -= 3;
			threeCount++;
		}
	}

	return threeCount;
}
int FindOther(vector<Node>  color) {

	int otherCount = 0;
	

	for (int i = 0; i < color.size(); i++) {

		vector<Node> temp = color;
		int tempCount = 0;
		for (int j = 0; j < temp.size(); j++) {
			int count = 0;
			if (temp[j].count > 0) {
				for (int k = j; k < j + 2 && j+2 < temp.size(); k++) {

					if (temp[k].num + 1 == temp[k + 1].num && temp[k].count >= 1 && temp[k + 1].count >= 1) {
						count++;
					}
				}

				if (count == 2) {

					for (int k = j; k < j + 3; k++) {
						temp[k].count--;
					}
					tempCount++;
				}
			}
		}

		if (otherCount < tempCount) {
			otherCount = tempCount;
		}
	}

	return otherCount;
}

void sort(vector<Node> &a)
{
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size() - 1; j++) {
			if (!cmp(a[j], a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void sort2(vector<Node> &a)
{
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size() - 1; j++) {
			if (!cmp2(a[j], a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
int main() {

	int  testCase;

	cin >> testCase;

	for (int t = 1; t <= testCase; t++) {

		string num;
		string color;

		cin >> num >> color;

		vector<Node> arr;
		for (int i = 0; i < num.size(); i++) {

			if (!check(num[i], color[i], arr)) {
				arr.push_back(Node(num[i], color[i],1));
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr.size() - 1; j++) {
				if (!cmp(arr[j],arr[j + 1])) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		sort(arr);

		//count 정렬 완료

		//R일 때 , G일 때, B일 떄 경우로 카운트 체크
		int maxR = 0;
		int maxG = 0;
		int maxB = 0;
		vector<Node> R;
		vector<Node> G;
		vector<Node> B;

		for (int i = 0; i < arr.size(); i++) {

			if (arr[i].color == 'R') {
				R.push_back(Node(arr[i].num, arr[i].color, arr[i].count));
			}
			else if (arr[i].color == 'G') {
				G.push_back(Node(arr[i].num, arr[i].color, arr[i].count));
			}
			else if (arr[i].color == 'B') {
				B.push_back(Node(arr[i].num, arr[i].color, arr[i].count));
			}
		}

		sort2(R);
		sort2(G);
		sort2(B);

		arr.clear();

		int RThree = FindThree(R);
		int Relse = FindOther(R);

		int GThree = FindThree(G);
		int Gelse = FindOther(G);

		int BThree = FindThree(B);
		int Belse = FindOther(B);

		int all = RThree + Relse + GThree + Gelse + BThree + Belse;
		if (all >= 3) {
			cout << "#" << t << " " << "Win" << endl;
		}
		else {
			cout << "#" << t << " " << "Continue" << endl;
		}

		R.clear();
		G.clear();
		B.clear();
	}
}