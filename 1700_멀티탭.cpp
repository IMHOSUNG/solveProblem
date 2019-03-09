#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
2 15
3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
답: 2
*/

vector<int> a;
vector<int> con;

int find(int a) {

	for (int i = 0; i < con.size(); i++) {

		if (a == con[i])
			return i;
	}

	return -1;
}

int main() {

	int num, count;

	cin >> num >> count;

	int input = 0;

	for (int i = 0; i < count; i++) {
		
		cin >> input;
		a.push_back(input);
	}

	con.resize(num);

	int answer = 0;

	for (int i = 0; i < a.size(); i++) {

		int flag = 0;
		for (int j = 0; j < con.size(); j++) {

			if (con[j] == a[i]) {
				flag = 1;
				break;
			}
		}

		//없었을 경우
		if (flag == 0) {

			int flag2 = 0;
			//비어 있는 곳이 있을 경우 
			for (int k = 0; k < con.size(); k++) {
				if (con[k] == 0) {
					con[k] = a[i];
					flag2 = 1;
					break;
				}
			}

			//비어 있는 곳이 없을 경우
			if (flag2 == 0) {
				int flag3 = 0;
				vector<int> temp;
				temp.resize(con.size());
				int differ_count = 0;
				for (int x = 0; x < con.size(); x++) {

					for (int y = i; y < a.size(); y++) {

						if (find(a[y])==-1) {
							differ_count++;
						}
						else {
							int index = find(a[y]);
							temp[index] = 1;
						}

						if (differ_count == num) {
							for (int z = 0; z < temp.size(); z++) {
								if (temp[z] == 0) {
									con[z] = a[i];
									temp.clear();
									flag3 = 1;
									answer++;
									break;
								}
							}
							break;
						}
					}
					if (flag3 == 1) {
						break;
					}
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}