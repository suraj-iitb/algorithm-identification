#include <iostream>
using namespace std;

int main() {
	int n, swap=0;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n -1; i++)
		for(int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1]) {
				a[j] = a[j - 1] - a[j];
				a[j - 1] -= a[j];
				a[j] += a[j - 1];
				swap += 1;
			}
	for (int i = 0; i < n-1; i++)
		cout << a[i] << ' ';
		cout << a[n - 1] << endl;
		cout << swap << endl;
	return 0;
}
