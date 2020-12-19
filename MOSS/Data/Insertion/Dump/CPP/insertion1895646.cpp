#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	cout << a[0];
	for (int i = 1; i < n; i++)cout << " " << a[i]; cout << endl;
	
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		cout << a[0];
		for (int i = 1; i < n; i++)cout << " " << a[i]; cout << endl;
	}
	return 0;
}
