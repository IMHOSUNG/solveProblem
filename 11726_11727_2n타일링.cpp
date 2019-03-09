#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int main() {

	int num;
	cin >> num;

	//1번 1개 2번 2개 3번 3개 4번 5개 .... 피보나치 와 동일

	arr.resize(2);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= num; i++) {
		
		//소수로 나눠준다 (자료형 범위 때문에)
		if (i % 2 == 0)
		{
			arr.push_back((arr[i-1]*2 + 1) % 10007);
		}
		else
		{
			arr.push_back((arr[i - 1] * 2 - 1) % 10007);
		}
	}

	cout << arr[num] << endl;
}