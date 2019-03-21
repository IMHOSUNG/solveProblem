#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int map[10000000] = { 0 };

//에라토스테니스의 체
// index i 가 prime 검사를 받지 않은 상태면
// i 이후의 i 배수는 약수로 i를 가지고 있는 것이 되므로
// i 이후의 i 배수에 대해 prime이 아니라는 상태 처리를 해준다.
// 
// end의 제곱근 보다 작은 prime으로 체를 만들 수 있음
// 2의 배수로 모두 처리를 했다면
// 4의 배수는 2를 약수로 가지고 있는 것이 되기 때문에 
// 모두 prime이 아니라는 상태 처리를 해준다.
// 마찬가지로 3이 소수면 그 이후의 숫자들은 모두 소수가 아니다
// 따라서 j+= prime의 원리는 그 해당 prime의 배수라고 할 수 있다.

// 2를 예로 들 경우 2가 소수이고
// 4, 6 , 8, 10 , 12...
// 3을 예로 들 경우 3이 소수이며
// 9, 12 , 15 ,18 ....
// 등을 통해 겹치는 수를 최소화 한다


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