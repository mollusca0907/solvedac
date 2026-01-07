#include <iostream>
#include <cmath>
using namespace std;

int arr[15]; //[row] = cor;

int n = 0;
int result = 0;


bool is_safe(int row, int col) {

	for (int i = 0; i < row; i++) {
		
		if (arr[i] == col) {
			return false;
		}
		if (abs(arr[i] - col) == abs(i - row)) {
			return false;
		}
	}
	return true;
}

void backtrack(int row) {
	if (row == n) {
		result++;
		return;
	}


	for (int col = 0; col < n; col++) {

		if (is_safe(row, col)) {
			arr[row] = col;
			backtrack(row + 1);
		}

	}

}

int main() {

	cin >> n;
	backtrack(0);

	cout << result;

}