#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<int> errorButton;
vector<int> channel;

int ClickNum = 0;

int checkAllButtonClear() {

	for (int i = 0; i < channel.size(); i++) {
		if (errorButton[channel[i]] == 1) {
			return 0;
		}
	}

	return 1;
}

void makeAll(string in, int num) {

	int size = 0;
	//���� ���� �� �Ǽ��� ������ Ʋ��...
	//�����ϴ� �κ� �� �� ������ ��
	//�߰������� string�� empty �� ��
	//stoi �� ���� ���� �߻� >> ����ִ� �� �ƴ��� ���Ŀ��� ���� ó�� ���� ��
	if (in.size() <= 6 && size <= 500000) {

		int flag = 0;
		for (int i = 0; i < 10; i++) {

			if (errorButton[i] == 0) {
				string temp;
				temp += in + char(i + '0');
				makeAll(temp, num);
			}
		}
		size = stoi(in);
		int click = in.size() + abs(size - num);

		//cout << click << endl;

		if (click < ClickNum) {
			ClickNum = click;
		}
	}
}

int main() {

	int CurCh = 100;

	errorButton.resize(10);

	string WantCh;
	cin >> WantCh;
	int watchint = stoi(WantCh);

	for (int i = 0; i < WantCh.size(); i++) {

		channel.push_back(WantCh[i] - '0');
	}

	int ErrorButton = 0;

	cin >> ErrorButton;

	for (int i = 0; i < ErrorButton; i++) {
		int input;

		cin >> input;
		errorButton[input] = 1;
	}

	//+�Ǵ� - ������ �̵��Ͽ��� ���� ����Ʈ ��
	ClickNum = abs(watchint - CurCh);

	// �ش� �ϴ� ä���� ��� ��ư�� ����
	if (checkAllButtonClear()) {

		if (ClickNum > channel.size()) {
			ClickNum = channel.size();
		}
	}
	// �ϳ��� �������� ������ ��
	else {
		//��ü Ž��
		for (int i = 0; i < 10; i++) {

			if (errorButton[i] == 0) {
				string temp;
				temp += char(i + '0');
				makeAll(temp, watchint);
			}
		}
	}

	cout << ClickNum << endl;
}