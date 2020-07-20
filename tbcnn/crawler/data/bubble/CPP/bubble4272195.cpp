#include<iostream>
#include<stdio.h>
using namespace std;

void reverse(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int bubblesort(int a[], int n) {
	int v = 0;
	int j = 20000;

	while (j >= 0) {
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				reverse(&a[i], &a[i - 1]);
				v++;
			}
		}
		j--;
	}

	return v;
}

int main() {
	int n;
	int a[100];
	int vv;

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	vv = bubblesort(a, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	cout << vv;
	cout<<endl;

	return 0;
}
