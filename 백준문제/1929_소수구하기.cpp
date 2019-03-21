#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int map[10000000] = { 0 };

//�����佺�״Ͻ��� ü
// index i �� prime �˻縦 ���� ���� ���¸�
// i ������ i ����� ����� i�� ������ �ִ� ���� �ǹǷ�
// i ������ i ����� ���� prime�� �ƴ϶�� ���� ó���� ���ش�.
// 
// end�� ������ ���� ���� prime���� ü�� ���� �� ����
// 2�� ����� ��� ó���� �ߴٸ�
// 4�� ����� 2�� ����� ������ �ִ� ���� �Ǳ� ������ 
// ��� prime�� �ƴ϶�� ���� ó���� ���ش�.
// ���������� 3�� �Ҽ��� �� ������ ���ڵ��� ��� �Ҽ��� �ƴϴ�
// ���� j+= prime�� ������ �� �ش� prime�� ������ �� �� �ִ�.

// 2�� ���� �� ��� 2�� �Ҽ��̰�
// 4, 6 , 8, 10 , 12...
// 3�� ���� �� ��� 3�� �Ҽ��̸�
// 9, 12 , 15 ,18 ....
// ���� ���� ��ġ�� ���� �ּ�ȭ �Ѵ�


int main() {

	int start, end;
	scanf("%d %d", &start, &end);

	if (end <= 1) {
		return 0;
	}

	for (int prime = 2; prime*prime <= end; prime++) {

		if (map[prime] == 0) {
			for (int j = prime * prime; j <= end; j += prime) {
				map[j] = 1;
			}
		}
	}

	for (int i = start; i <= end; i++) {
		if (map[i] == 0 && i != 1) {
			printf("%d\n", i);
		}
	}


}