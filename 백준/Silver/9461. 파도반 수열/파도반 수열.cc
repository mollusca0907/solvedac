#include <iostream>
using namespace std;

int main() {
    long long dp[101] = { 1, 1, 1 };
    for (int i = 3; i <= 100; ++i) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n - 1] << "\n";
    }

    return 0;
}
