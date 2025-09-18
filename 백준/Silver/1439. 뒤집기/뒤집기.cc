#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}


int main() {

	
	string s;
	cin >> s;

	int len = s.length();

	int cnt0 = 0, cnt1 = 0;

	char prev_c = s[0];
	for (int i = 1; i < len; i++) {
		if (prev_c != s[i]) {
			switch (prev_c) {
			case '0':
				cnt0++;
				break;
			case '1':
				cnt1++;
				break;
			}
		}
		prev_c = s[i];
	}

	int max = (cnt0 > cnt1) ? cnt0 : cnt1;
	cout << max;
	
	

	return 0;
}