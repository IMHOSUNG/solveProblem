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
	//정지 조건 문 실수로 여러번 틀림...
	//정지하는 부분 꼭 잘 생각할 것
	//추가적으로 string이 empty 일 때
	//stoi 를 쓰면 에러 발생 >> 비어있는 지 아닌지 추후에는 예외 처리 해줄 것
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

	//+또는 - 만으로 이동하였을 때를 디폴트 값
	ClickNum = abs(watchint - CurCh);

	// 해당 하는 채널의 모든 버튼이 정상
	if (checkAllButtonClear()) {

		if (ClickNum > channel.size()) {
			ClickNum = channel.size();
		}
	}
	// 하나라도 비정상이 존재할 때
	else {
		//전체 탐색
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