#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int main() {

	int num;
	cin >> num;

	//1�� 1�� 2�� 2�� 3�� 3�� 4�� 5�� .... �Ǻ���ġ �� ����

	arr.resize(2);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= num; i++) {
		
		//�Ҽ��� �����ش� (�ڷ��� ���� ������)
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