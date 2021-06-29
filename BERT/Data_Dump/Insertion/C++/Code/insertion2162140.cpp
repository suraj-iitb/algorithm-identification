#include <iostream>
using namespace std;
inline void put(int a[], int n) {
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << ' ' << a[i];
	}
	cout << endl;
}
inline void sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j+1] = a[j];
			j--;
		}
		a[j + 1] = v;
		put(a, n);
	}
}
int main() {
	const int num = 1000;
	int ar[num];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	put(ar, n); 
	sort(ar, n);
	return 0;

}
