#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Arr {
public:
	int IndexA;
	int ValueA;
	int ValueP;
	int IndexP;

	Arr(int IndexA, int ValueA): IndexA(IndexA), ValueA(ValueA) {

		IndexP = IndexA;
	}
};
vector<Arr> a;

//���� ������ �����ϴ� ��..(���� ���� ����� �ϰ� Ǯ��)
bool sortFun(Arr& a, Arr& b) {

	if (a.ValueA < b.ValueA) {
		return true;
	}
	else if(a.ValueA > b.ValueA){
		return false;
	}
	else {
		if (a.IndexA < b.IndexA) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool sortFun2(Arr& a, Arr& b) {

	if (a.IndexP < b.IndexP) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int Num;
	cin >> Num;

	for (int i = 0; i < Num; i++) {

		int input;
		cin >> input;
		a.push_back(Arr(i, input));
	}

	sort(a.begin(), a.end(), sortFun);

	for (int i = 0; i < Num; i++) {
		a[i].ValueP = i;
	}

	sort(a.begin(), a.end(), sortFun2);

	for (int i = 0; i < Num; i++) {
		cout << a[i].ValueP << " ";
	}
	cout << endl;
}