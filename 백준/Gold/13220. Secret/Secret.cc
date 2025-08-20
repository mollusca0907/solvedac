#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> getpi(vector<ll>& pattern) {

	int size = pattern.size();
	vector<ll> pi(size, 0);
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

vector<ll> kmp(vector<ll>& pattern, vector<ll>& s) {
	vector<ll> ans;
	int p_size = pattern.size();
	int s_size = s.size();

	vector<ll> pi = getpi(pattern);

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

	int n;
	cin >> n;

	vector<ll> pat;
	vector<ll> s(n*2);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pat.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i + n] = s[i];
	}
	s.pop_back();

	auto ans = kmp(pat, s);
	
	if (ans.size() == 0) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}

	return 0;
}