#include <iostream>
#include <string>
using namespace std;

int function(string & input) {

	//�켱 A,B�� ¦���� ���� ����
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

		//¦���� �� ���� Ȯ���ϸ� ���� ���� ��Ƽ� ���� ���� ���̿�
		//�ڽŰ� �ٸ� ���ĺ��� Ȧ���� ������ ������ �� ���� ����
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
	//��ġ������ �ؾ� �ϴϱ�...
	//���� �� ���� ������ ��� Ž��
	//���� �� A ���̿� B�� Ȧ���� ������ ������ �ȵ�..
	
	//�ٵ� ¦������ üũ������ϳ�... �� ����ϸ� �̰� ���� ����� �ְ���
	int num = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		string input;
		cin >> input;

		count_ += function(input);
	}

	cout << count_ << endl;
}