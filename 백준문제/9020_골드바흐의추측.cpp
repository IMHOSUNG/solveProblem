#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> map;
void MakeMap() {

	map.resize(100000);
	for (int prime = 2; prime*prime <= 10000; prime++) {

		for (int check = prime * prime; check <= 10000; check += prime) {

			if (map[check] == 0) {
				map[check] = 1;
			}
		}
	}

}

void PrimeCheck(int evenNum) {

	int front, back;
	for (int i = 2; i <= evenNum; i++) {
		if ((map[i]==0 && map[evenNum-i]==0)  &&(i <= evenNum-i)) {
			front = i;
			back = evenNum - i;
		}
	}

	printf("%d %d\n", front, back);
}

int main() {

	int testCase;
	scanf("%d", &testCase);

	MakeMap();
	for (int i = 0; i < testCase; i++) {

		int evenNum;

		scanf("%d", &evenNum);

		PrimeCheck(evenNum);
	}
}