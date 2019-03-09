#include <iostream>
#include <string>
using namespace std;

int function(string & input) {

	//우선 A,B가 짝수개 인지 부터
	int counta = 0;
	int countb = 0;
	for (int i = 0; i < input.size(); i++) {

		if (input[i] == 'A') {
			counta++;
		}
		if (input[i] == 'B') {
			countb++;
		}
	}

	if (counta % 2 == 0 && countb % 2 == 0) {

		//짝수개 인 것을 확인하면 끝과 끝을 잡아서 서로 검출 사이에
		//자신과 다른 알파벳이 홀수개 있으면 무조건 한 점이 생김
		int temp = input.size() - 1;
		for (int front = 0; front < input.size(); front++) {

			for (int back = temp; back > front; back--) {
				
				if (input[front] == input[back]) {

					if ((back - front - 1) % 2 != 0 ) {
						return 0;
					}
					else {
						
						int co = 0;
						for (int i = front + 1; i < back; i++) {

							if (input[front] != input[i]) {
								co++;
							}
						}

						if (co % 2 != 0) {
							return 0;
						}

					}
					temp = back - 1;
					break;
				}
			}
		}

		return 1;
		
	}
	else {
		return 0;
	}
}

int main() {

	int count_ = 0;
	//아치형으로 해야 하니까...
	//시작 끝 시작 끝으로 계속 탐색
	//예를 들어서 A 사이에 B가 홀수개 있으면 무조건 안됨..
	
	//근데 짝수개는 체크해줘야하나... 뭐 통과하면 이걸 보는 사람이 있겠지
	int num = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		string input;
		cin >> input;

		count_ += function(input);
	}

	cout << count_ << endl;
}