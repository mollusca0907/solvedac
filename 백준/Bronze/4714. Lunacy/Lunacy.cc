#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while (1) {
        double X;
        cin >> X;
        
        if (X == -1.0) break;
        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", X, X * 0.167);
    }
    
    return 0;
}