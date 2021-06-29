#include<iostream>
#define max 150
using namespace std;
void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << a[i];
	}
	cout << endl;
}
void insertsort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[j + 1] < a[j]) {
				int swap = a[j + 1];
				a[j + 1] = a[j];
				a[j] = swap;
			}
		}
		print(a, n);
	}
}
int main() {
	int n;
	cin >> n;
	int a[max];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	print(a, n);
	insertsort(a, n);

}
