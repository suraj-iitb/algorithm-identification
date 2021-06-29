#include<iostream>
using namespace std;

int main() {
	int n,sw=0;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n-1; i++) {
		int minv = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minv]) {
				minv = j;
			}
		}
		if (minv != i) {
			swap(arr[minv], arr[i]);
			++sw;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i != n - 1)
			cout << ' ';
	}
	cout << endl << sw << endl;
	delete[] arr;
	return 0;
}
