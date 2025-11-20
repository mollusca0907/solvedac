#include <bits/stdc++.h>
using namespace std;

int main() {

	string input;
	cin >> input;

	int a = 0, b = 0;

	int xpos = -1;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'x') {
			xpos = i;
			break;
		}
	}

	if (xpos != -1) {
		string temp_a = input.substr(0,xpos);
		if (temp_a == "") {
			a = 1;
		}
		else if (temp_a == "-") {
			a = -1;
		}
		else {
			a = stoi(temp_a);
		}
	}
	if (input[xpos + 1] != '\0') {
		b = stoi(input.substr(xpos + 1, input.length()));
	}

	cout << a;

}