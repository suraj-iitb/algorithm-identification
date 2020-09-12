#include<iostream>

using namespace std;

int main() {
	int n,a[1000];

	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];

	for (int i = 0; i < n; i++) {
		int temp,j;
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			a[j] = temp;
			j--;
		}
		for (int k = 0; k < n; k++) {
			if (k < n - 1)cout << a[k] << " ";
			else cout << a[k] << endl;
		}
	}
	return 0;
}
