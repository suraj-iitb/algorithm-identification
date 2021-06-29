#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int swapCount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				swapCount++;
			}
		}
	}
	for (int i = 0; i < n-1; i++) {
		cout << a[i]<<' ';
	}
	cout << a[n - 1] << '\n' << swapCount<<'\n';
}
