#include <bits/stdc++.h>
using namespace std;


struct Trie {
	bool is_end;
	Trie* next[10];

	Trie() {
		is_end = false;
		fill(next, next + 10, nullptr);
	}

	bool insert(string& s) {
		Trie* node = this;
		for (char c : s) {
			int idx = c - '0';
			if (!node->next[idx]) {
				node->next[idx] = new Trie();
			}
			node = node->next[idx];

			if (node->is_end) {
				return false;
			}
		}
		
		for (int i = 0; i < 10;i++) {
			if (node->next[i] != nullptr) {
				return false;
			}
		}

		node->is_end = true;
		return true;

	}

};

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		vector<string> num;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			num.push_back(s);
		}

		sort(num.begin(), num.end());

		Trie* root = new Trie();

		bool ok = true;

		for (auto it : num) {
			if (!root->insert(it)) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}


	}
	return 0;

}