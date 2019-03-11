#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class P{
public:
	int from;
	int to;

	P(int from, int to) : from(from), to(to) {};
};

vector<P> arr;
void hanoiFunc(int n, int from, int by, int to) {

	if (n != 0) {
		hanoiFunc(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoiFunc(n - 1, by, from, to);
	}
}

int main() {

	int n;
	cin >> n;

	printf("%d\n",(int)pow(2, n) - 1);

	hanoiFunc(n, 1, 2, 3);
}