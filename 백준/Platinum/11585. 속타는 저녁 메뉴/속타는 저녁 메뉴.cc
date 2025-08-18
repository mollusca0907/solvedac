#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> getpi(vector<int>& pattern) {

	int size = pattern.size();
	vector<int> pi(size, 0);
	int start = 1;
	int matched_len = 0;

	while (start + matched_len < size) {
		if (pattern[start + matched_len] == pattern[matched_len]) {
			matched_len++;
			pi[start + matched_len - 1] = matched_len;
		}
		else { 
			if (matched_len == 0) {
				start++; 
			}
			else {
				start += matched_len - pi[matched_len - 1];
				matched_len = pi[matched_len - 1];
			}
		}
	}

	return pi;
}

vector<int> kmp(vector<int>& pattern, vector<int>& s) {
	vector<int> ans;
	int p_size = pattern.size();
	int s_size = s.size();

	vector<int> pi = getpi(pattern);

	int start = 0;
	int matched_len = 0;

	while (start <= s_size - p_size) {
		if (matched_len < p_size && s[start + matched_len] == pattern[matched_len]) {
			matched_len++;
			if (matched_len == p_size) {
				ans.push_back(start);
			}
		}
		else {
			if (matched_len == 0) {
				start++;
			}
			else {
				start += matched_len - pi[matched_len - 1];
				matched_len = pi[matched_len - 1];
			}
		}
	}
	return ans;
}


int main() {

	vector<int> v1;
	vector<int> v2;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		v1.push_back(x - 'A');
	}
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		v2.push_back(x - 'A');
	}
	for (int i = 0; i < n; i++) {
		v1.push_back(v1[i]);
	}
	v1.pop_back();

	auto ans = kmp(v2, v1);

	int cnt = ans.size();

	int d = gcd(n, cnt);
	if (cnt >= n) {
		cout << "1/1";
	}
	else {
		cout << cnt / d << "/" << n / d;
	}

	return 0;
}