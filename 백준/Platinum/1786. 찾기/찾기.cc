#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getpi(string& pattern) {

	int size = pattern.size();
	vector<int> pi(size, 0);

	int begin = 1;
	int matched_cnt = 0;

	while (begin + matched_cnt < size) {
		if (pattern[begin + matched_cnt] == pattern[matched_cnt]) {
			matched_cnt++;
			pi[begin + matched_cnt - 1] = matched_cnt;
		}
		else {
			if (matched_cnt == 0) {
				begin++;
			}
			else {
				begin += matched_cnt - pi[matched_cnt - 1];
				matched_cnt = pi[matched_cnt - 1];
			}
		}

	}
	return pi;
}

vector<int> kmp(string& pattern, string& s) {
	vector<int> ans;

	int p_size = pattern.size();
	int s_size = s.size();
	auto pi = getpi(pattern);

	int begin = 0;
	int matched_cnt = 0;

	while (begin <= s_size - p_size) {
		if (matched_cnt < p_size && s[begin + matched_cnt] == pattern[matched_cnt]) {
			matched_cnt++;
			if (matched_cnt == p_size) {
				ans.push_back(begin);
			}
		}
		else {
			if (matched_cnt == 0) {
				begin++;
			}
			else {
				begin += matched_cnt - pi[matched_cnt - 1];
				matched_cnt = pi[matched_cnt - 1];
			}
		}
	}
	return ans;
}

int main() {

	string s, pattern;
	getline(cin, s);
	getline(cin, pattern);

	auto matched = kmp(pattern, s);
	cout << matched.size() << "\n";
	for (auto i : matched) {
		cout << i+1 << " ";
	}
	return 0;
}