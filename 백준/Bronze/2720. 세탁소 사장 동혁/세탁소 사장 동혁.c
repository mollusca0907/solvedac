#include <stdio.h>

int main() {

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int c;
        scanf("%d", &c);

        int quarter, dime, nickel, penny;
        for (quarter = 0; c >= 25; quarter++) {
            c -= 25;
        }
        for (dime = 0; c >= 10; dime++) {
            c -= 10;
        }
        for (nickel = 0; c >= 5; nickel++) {
            c -= 5;
        }
        for (penny = 0; c >= 1; penny++) {
            c -= 1;
        }

        printf("%d %d %d %d\n", quarter, dime, nickel, penny);
    }
    
    return 0;
}

