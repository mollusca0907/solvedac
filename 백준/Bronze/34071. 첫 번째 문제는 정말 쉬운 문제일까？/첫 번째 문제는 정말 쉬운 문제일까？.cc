#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int hard, ez, fir;
    cin >> fir;
    ez = 0x7FFFFFFF;
    hard = 0;

    ez = min(ez, fir);
    hard = max(hard, fir);

    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;

        ez = min(ez, t);
        hard = max(hard, t);
    }

    if (fir == ez) cout << "ez";
    else if (fir == hard) cout << "hard";
    else cout << "?";
}
