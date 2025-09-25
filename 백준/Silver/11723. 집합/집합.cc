#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int s = 0;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {

		string command;
		cin >> command;
		int x;

		if (command == "add") {
			cin >> x;
			s |= (1 << (x - 1));
		}
		else if (command == "remove") {
			cin >> x;
			s &= (~(1 << (x - 1)));
		}
		else if (command == "check") {
			cin >> x;
			cout << (s >> (x - 1) & 1) << "\n";
		}
		else if (command == "toggle") {
			cin >> x;
			s ^= (1 << (x - 1));
		}
		else if (command == "all") {
			s = 0x7fffffff;
		}
		else {
			s = 0;
		}


	}
	


	return 0;
}