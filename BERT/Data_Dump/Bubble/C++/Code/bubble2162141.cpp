#include <iostream>
using namespace std;
inline int bubblesort(int a[], int  n) {
	int sw = 0;
	bool flag = 1;
	for (int i = 0; flag; i++) {
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}
int main() {
	const int n = 100;
	int ar[n];
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> ar[i];
	}
	int sum = bubblesort(ar, num);
	cout << ar[0];
	for (int i = 1; i < num; i++)
		cout << ' ' << ar[i];
	cout << endl;
	cout << sum << endl;
	return 0;
}
