#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (auto &x : v) cout << x << "\n";
}
