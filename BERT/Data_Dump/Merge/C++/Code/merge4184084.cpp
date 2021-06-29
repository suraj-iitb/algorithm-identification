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

int CNT = 0;

void printArr(int a[], int len) {

	for (int i = 0; i < len; i++) {
		if (i == 0) cout << a[0];
		else cout << " " << a[i];
	}
	cout << endl;
}

void merge(int a[], int left, int mid, int right) {

	//if (right - left == 1) return;

	int Llen = mid - left;
	int Rlen = right - mid;
	int* L = new int[Llen + 1];
	int* R = new int[Rlen + 1];

	for (int i = 0; i < Llen; i++) {
		L[i] = a[left + i];
	}
	L[Llen] = INT_MAX;
	for (int i = 0; i < Rlen; i++) {
		R[i] = a[mid + i];
	}
	R[Rlen] = INT_MAX;

	int ll = 0, rr = 0;
	for (int i = left; i < right; i++) {
		CNT++;
		if (L[ll] <= R[rr]) {
			a[i] = L[ll++];
		}
		else {
			a[i] = R[rr++];
		}
	}

	delete[] L;
	delete[] R;
}

void mergeSort(int a[], int left, int right) {

	if (left + 1< right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid, right);
		merge(a, left, mid, right);
	}
}



int main() {

	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)	{
		scanf("%d", &a[i]);
	}

	mergeSort(a, 0, n);
	printArr(a, n);
	cout << CNT << endl;

	return 0;
}

