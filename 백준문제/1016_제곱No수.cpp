#include <iostream>
using namespace std;

//int 배열은 크지만, char, bool 배열은
//1byte이기 때문에 메모리의 여유가 있다
int map[1000001] = { 0 };
unsigned long long answer = 0;

int main() {

	unsigned long long min, max;

	cin >> min >> max;

	for (unsigned long long i = 2; i*i <= max; i++) {

		//시작점 지정
		unsigned long long s = min / (i*i);
		//만약 안 떨어지는 것이면 하나 더 해줌
		if (s*(i*i) != min) s++;

		//시작점 a 넣어주고, 현재 i값 제곱 곱하기 시작점 곱 a 가 max보다 작으면 map에 1을 넣어줌
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