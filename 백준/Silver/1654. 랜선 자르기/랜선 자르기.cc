#include <iostream>
#include <vector>

using namespace std;

int main() {

    int k, n;

    cin >> k >> n;

    vector<int> lan(k);

    int max_len = 0;

    for (int i = 0; i < k; i++) {

        cin >> lan[i];

        max_len = max(max_len, lan[i]);

    }

    long long left = 1;

    long long right = max_len;

    long long mid = (left + right) / 2;

    

    while (left <= right) {

        int count = 0;

        for (int i = 0; i < k; i++) {

            count += lan[i] / mid;

        }

        if (count >= n) {

            left = mid + 1;

        }

        else {

            right = mid - 1;

        }

        mid = (left + right) / 2;

    }

    cout << mid << endl;

    return 0;

}