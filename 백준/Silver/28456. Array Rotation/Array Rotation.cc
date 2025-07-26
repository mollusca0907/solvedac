#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101] = { 0, };
int temp[101][101] = { 0, };
//int ans[100][100] = { 0, };


int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	int q;
	cin >> q;

	for (int k = 0; k < q; k++) {
		int command;
		cin >> command;

		if (command == 1) {
			int row;
			cin >> row;
			int temp = arr[row][n];
			for (int j = n; j > 1; j--) {
				arr[row][j] = arr[row][j - 1];
			}
			arr[row][1] = temp;
		}
		else {
			
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					temp[j][n - i + 1] = arr[i][j];
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					arr[i][j] = temp[i][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}