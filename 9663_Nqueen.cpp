#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int answer = 0;

class Pos {
public:
	int y;
	int x;

	Pos(int y, int x) : y(y), x(x) {}
};

vector<Pos> stack;

int check(int current_y , int x, int n) {

	for (vector<Pos>::size_type i = 0; i < current_y-1; i++) {

		if (stack[i].x == x || abs(stack[i].y - stack[i].x) == abs(current_y - x)) {
			return 0;
		}
	}

	return 1;
}

void dfs(int current_y, int n) {

	cout << current_y << endl;
	if (current_y > n) {
		answer++;
	}
	else{
	
		for (int x = 1; x <= n; x++)
		{
			stack.push_back(Pos(current_y, x));
			if (check(current_y, x, n)) {
				dfs(current_y + 1, n);
			}
			else {
				stack.pop_back();
			}
		}
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		
		stack.push_back(Pos(1, i));
		dfs(2, n);
	}

	cout << answer << endl;
}