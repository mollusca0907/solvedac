#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 2;
    while (a - b >= 0) {
        a -= b;
        swap(a, b);
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
