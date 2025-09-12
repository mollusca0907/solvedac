#include <stdio.h>

void hanoi(int n, int start, int end, int mid);

int main() {

    int n;
    scanf("%d", &n);
    
    printf("%d\n", (1 << n) - 1);

    hanoi(n, 1, 3, 2);
    
    return 0;
}


void hanoi(int n, int start, int end, int mid) {

    if (n == 0) {
        return;
    }
    else {

        hanoi(n - 1, start, mid, end);
        printf("%d %d\n", start, end);
        hanoi(n - 1, mid, end, start);

    }
}
