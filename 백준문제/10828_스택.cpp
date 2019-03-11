#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> stack;
int main() {

	int top = -1;

	int number;

	cin >> number;


	for (int i = 0; i < number; i++) {
		
		string input;
		cin >> input;
		if (input == "push") {
			int number = 0;
			cin >> number;
			stack.push_back(number);
			top++;
		}
		else if (input == "pop") {
			if (top == -1) {
				cout << "-1" << endl;
			}
			else {
				cout << stack[top--] << endl;
				stack.pop_back();
			}
		}
		else if (input == "size") {
			cout << top+1 << endl;
		}
		else if (input == "empty") {
			if (top == -1) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (input == "top"){
			if (top == -1) {
				cout << "-1" << endl;
			}
			else {
				cout << stack[top] << endl;
			}
		}

	}
}