#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[9];
bool used[9];

void backtrack(int depth) {

	if (depth == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = true;
			arr[depth] = i;
			backtrack(depth + 1);
			used[i] = false;
		}

	}

}


int main() {

	cin >> n;
	backtrack(0);

	return 0;
}