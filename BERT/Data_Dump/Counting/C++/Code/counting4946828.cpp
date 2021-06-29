#include<iostream>
#define max 2000001
using namespace std;
int n;
void countingsort(int a[], int b[], int k) {
	int c[max];
	for (int i = 0; i <= k; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		c[i] += c[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}

}
int main() {
	int a[max];
	int b[max] = { -1 };
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (k < a[i])k = a[i];
	}
	countingsort(a, b, k);


	for (int i = 0; i < n; i++) {
		if (i)cout << " ";
		cout << b[i];
	}
	cout << endl;
}
