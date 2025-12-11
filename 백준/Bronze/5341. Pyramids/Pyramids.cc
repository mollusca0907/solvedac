#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if (n==0){
            return 0;
        }
        long long sum = 0;
        while(n>=0){
            sum += n;
            n--;
        }
        cout << sum << "\n";
    }
    
    return 0;
}