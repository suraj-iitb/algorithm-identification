#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n,a[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int v;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			v = a[i];
			for (int j = i-1; j >= 0; j--) {
				if (a[j] > v) {
					a[j + 1] = a[j];
					a[j] = v;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			printf("%d", a[j]);
			if (j != n - 1) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
