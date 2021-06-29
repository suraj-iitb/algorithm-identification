#include<iostream>
#include<stdio.h>
using namespace std;

void reverse(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}	

int selectionsort(int a[], int n) {
	int b = 1;
	int c = 0;
	for (int i = 0; i < n; i++) {
		b = i;
		for (int j = i; j < n; j++) {
			if (a[b] > a[j])
				b = j;
		}
		if (a[i] > a[b]) {
			reverse(&a[i], &a[b]);
			c++;
		}
	}
	return c;
}

int main() {
	int n;
	int a[100];
	int vv;

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	vv = selectionsort(a, n);

	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	cout << vv;
	cout << endl;

	return 0;
}
