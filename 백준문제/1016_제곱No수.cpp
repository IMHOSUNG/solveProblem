#include <iostream>
using namespace std;

//int �迭�� ũ����, char, bool �迭��
//1byte�̱� ������ �޸��� ������ �ִ�
int map[1000001] = { 0 };
unsigned long long answer = 0;

int main() {

	unsigned long long min, max;

	cin >> min >> max;

	for (unsigned long long i = 2; i*i <= max; i++) {

		//������ ����
		unsigned long long s = min / (i*i);
		//���� �� �������� ���̸� �ϳ� �� ����
		if (s*(i*i) != min) s++;

		//������ a �־��ְ�, ���� i�� ���� ���ϱ� ������ �� a �� max���� ������ map�� 1�� �־���
		for (unsigned long long a = s; i*i*a <= max; a++) {
			map[i*i*a-min] = 1;
		}
	}

	for (unsigned long long i = 0; i <= max-min; i++) {

		if (map[i] == 0) {
			answer++;
		}
	}

	cout << answer << endl;
}