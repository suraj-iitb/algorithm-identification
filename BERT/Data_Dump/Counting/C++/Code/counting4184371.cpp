#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const double PI = 3.14159265358979;

void printArr(int a[], int len) {

	for (int i = 0; i < len; i++)
	{
		if (i == 0) cout << a[0];
		else cout << " " << a[i];
	}
	cout << endl;
}


void countingSort(int a[], int len, int max) {

	int* b = new int[max + 1] ();
	int* c = new int[len];

	for (int i = 0; i < len; i++) {
		b[a[i]]++;
		c[i] = a[i];
	}

	for (int i = 1; i < max + 1; i++) {
		b[i] += b[i - 1];
	}

	for (int i = len - 1; i >= 0; i--) {
		a[b[c[i]] - 1] = c[i];
		b[c[i]]--;
	}

	delete[] b;
	delete[] c;
}

int main() {

	int n; cin >> n;

	int* a = new int[n];

	int max = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (max < a[i]) max = a[i];
	}
	countingSort(a, n, max);
	printArr(a, n);

	delete[] a;
	
	return 0;
}

