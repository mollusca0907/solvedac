#include <iostream>
using namespace std;

long long offset = 0;
int r, c;

void recursion(int n) {
	long long size = 1 << n;
	if (size == 1 || n == 0) {
		return;
	}

	long long half = 1 << (n - 1);


	if (r < half && c < half) { //왼쪽위
		offset += 0 * (size * size) / 4;
		
	}
	else if (r < half && c >= half) { //오른쪽위
		offset += 1 * (size * size) / 4;
		c -= half;
	}
	else if (r >= half && c < half) {//왼쪽아래
		offset += 2 * (size * size) / 4;
		r -= half;
	}
	else if (r >= half && c >= half) {//오른쪽아래
		offset += 3 * (size * size) / 4;
		r -= half;
		c -= half;
	}
	recursion(n - 1);

}


int main() {

	int n;
	cin >> n >> r >> c;

	recursion(n);

	cout << offset;

}