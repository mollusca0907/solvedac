#include <iostream>
using namespace std;
typedef long double ld;

string x, y;

bool iszero(string& s) {
	int idx = 0;
	int slen = s.length();
	if (s.front() == '+' || s.front() == '-') idx++;
	while (idx < slen && s[idx] == '0') idx++;
	if (idx < slen && s[idx] == '.') {
		idx++;
		while (idx < slen && s[idx] == '0') idx++;
	}

	return idx == slen;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y;
	while (!(iszero(x) && iszero(y))) {
		if (iszero(x) || iszero(y)) cout << "AXIS\n";
		else {
			if (x.front() == '-') {
				if (y.front() == '-') cout << "Q3\n";
				else cout << "Q2\n";
			}
			else {
				if (y.front() == '-') cout << "Q4\n";
				else cout << "Q1\n";
			}
		}
		cin >> x >> y;
	}

	cout << "AXIS";
}