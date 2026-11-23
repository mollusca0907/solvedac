#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	string s;
	cin >> s;

	int mn = 5;

	for (int i = 0; i <= n-5; i++){
		int cnt = 5;
		if (s[i] == 'e') cnt--;
		if (s[i+1] == 'a') cnt--;
		if (s[i+2] == 'g') cnt--;
		if (s[i+3] == 'l') cnt--;
		if (s[i+4] == 'e') cnt--;
		mn = min(mn, cnt);
	}

	cout << mn;

	return 0;
}