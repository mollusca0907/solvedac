#include <bits/stdc++.h>
using namespace std;


struct Trie {
	bool is_end;
	Trie* next[26];

	Trie() {
		is_end = false;
		fill(next, next + 26, nullptr);
	}

	void insert(string& s) {
		Trie* node = this;
		for (char c : s) {
			int idx = c - 'a';
			if (!node->next[idx]) {
				node->next[idx] = new Trie();
			}
			node = node->next[idx];
		}
		node->is_end = true;
	}

	bool find(string& s) {
		Trie* node = this;
		for (char c : s) {
			int idx = c - 'a';
			if (!node->next[idx]) {
				return false;
			}
			node = node->next[idx];
		}
		return node->is_end;
	}


};

int main() {


	int n, m;
	cin >> n >> m;

	Trie* root = new Trie();

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		root->insert(s);
	}

	int ans = 0;

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		ans += root->find(s);
	}

	cout << ans;
}