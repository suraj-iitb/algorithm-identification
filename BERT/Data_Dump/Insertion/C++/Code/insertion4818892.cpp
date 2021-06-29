#include<bits/stdc++.h>

using namespace std;


static const int MAX = 200000;

void show(int a[],int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n");
}

void insertSort(int a[],int n) {
	for (int i = 1; i < n; ++i) {
		int y = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > y) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = y;
		show(a,n);
	}

}

int main() {
	int a[MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	show(a,n);
	insertSort(a,n);
	return 0;
}
