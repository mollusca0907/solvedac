#include <iostream>
#include <algorithm>
using namespace std;

long long int fibnum[91] = { 0, };

long long int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	if (fibnum[n] == 0) {
		fibnum[n] = fib(n - 1) + fib(n - 2);
		
	}
	return fibnum[n];
}

int main() {

	int n;
	cin >> n;
	cout << fib(n);

	return 0;
}