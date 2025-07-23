#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<int> num(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    stack<int> stk; // <-인덱스만 저장

    for (int i = 1; i <= n; i++) {
        while (!stk.empty()) {
            if (v[i] <= v[stk.top()]) {
                num[i] = stk.top();
                break;
            }
            else {
                stk.pop();

            }
        }
        stk.push(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << num[i] << " ";
    }

    return 0;
}