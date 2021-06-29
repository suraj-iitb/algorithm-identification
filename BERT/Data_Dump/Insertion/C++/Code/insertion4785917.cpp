#include<iostream>

using namespace std;

int const MAX_N = 100;
int arr[MAX_N] = {};

void print(int arr[MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i < n - 1) cout << " ";
	}
	cout << endl;
}

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		print(arr, n);
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
	}

	print(arr, n);

	return 0;
}

