#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<int> ans(n + 1, -1);
    stack<pair<int, int>> stk; //val, idx
    for (int i = 1; i <= n; i++) {
        int cur;
        cin >> cur;

        while (!stk.empty()) {
            if (cur > stk.top().first) {
                ans[stk.top().second] = cur;
                stk.pop();
            }
            else {
                break;
            }
        }
        stk.push({ cur, i });


    }

    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}