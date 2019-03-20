//���� ���� : ������ �ӵ��� �̵��ϴ� ����, �浹�ϸ� ���� �ݴ�
// ���� ������ ������, ������ �����̸� �� ���� id�� ���̰� ��������.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int AntMoveSpeed = 1;
int LeftRank = 0;
int RightRank = 0;
class Ant {
public:
	int Id;
	int Location;
	int Rank;
	int Time;
	int Direction;

	Ant(int Id, int Location) :Id(Id), Location(Location) {

		if (Id < 0) {
			this->Direction = -1;
		}
		else {
			this->Direction = 1;
		}
	}
};

bool lessThan(Ant &a, Ant& b) {

	if (a.Time < b.Time) {
		return true;
	}
	else if (a.Time == b.Time) {

		if (a.Id < b.Id) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
vector<Ant> AntArr;

int main() {

	int TestCase;
	cin >> TestCase;

	//���� 500000���� >> �ð� ���� 1��.. 2�� ���� �ʰ�x
	for (int k = 0; k < TestCase; k++) {

		int NumAnt, Length, Rank;
		cin >> NumAnt >> Length >> Rank;

		for (int j = 0; j < NumAnt; j++) {

			int A_D_Loc, A_Id;
			cin >> A_D_Loc >> A_Id;

			AntArr.push_back(Ant(A_Id, A_D_Loc));
		}


		//�ڽ��� ���ʿ��� 2��° ���
		//�ݴ��� ������ ���� ���̿� 2�� ���� �� ���� �� ����

		//Rank �ű��
		for (int i = 0; i < AntArr.size(); i++) {
			
			if (AntArr[i].Direction > 0) {
				RightRank++;
				AntArr[i].Rank = RightRank;
			}
		}
		for (int i = AntArr.size()-1; i >= 0; i--) {

			if (AntArr[i].Direction < 0) {
				LeftRank++;
				AntArr[i].Rank = LeftRank;
			}
		}

		vector<Ant> Temp = AntArr;
		for (int i = 0; i < Temp.size(); i++)
		{
			if (Temp[i].Direction > 0) {
				Temp[i].Time = Length - Temp[i].Location;
			}
			else {
				Temp[i].Time = Temp[i].Location;
			}
		}

		sort(Temp.begin(), Temp.end(), lessThan);

		cout << Temp[Rank - 1].Id << endl;

		AntArr.clear();
		Temp.clear();
	}

}