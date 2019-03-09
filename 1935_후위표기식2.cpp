#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> in;
vector<double> map;
vector<double> stack;

void check(vector<char> & in) {

	if (in[in.size() - 1] == '*') {
		double a = stack[stack.size() - 1];
		double b = stack[stack.size() - 2];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(a * b);
	}
	else if (in[in.size() - 1] == '+') {
		double a = stack[stack.size() - 1];
		double b = stack[stack.size() - 2];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(a + b);
	}
	else if (in[in.size() - 1] == '/') {
		double a = stack[stack.size() - 1];
		double b = stack[stack.size() - 2];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(b / a);
	}
	else if (in[in.size() - 1] == '-') {
		double a = stack[stack.size() - 1];
		double b = stack[stack.size() - 2];
		stack.pop_back();
		stack.pop_back();
		stack.push_back(b - a);
	}
	else {

		stack.push_back(map[(int)(in[in.size() - 1] - 65)]);
	}
}

int main() {

	int num = 0;
	cin >> num;
	string input;
	cin >> input;

	for (int i = 0; i < num; i++) {

		double value;
		cin >> value;
		map.push_back(value);
	}

	for (int i = 0; i < input.size(); i++) {

		in.push_back(input[i]);
		check(in);
	}

	cout << fixed;
	cout.precision(2);
	cout << stack[0] << endl;
}