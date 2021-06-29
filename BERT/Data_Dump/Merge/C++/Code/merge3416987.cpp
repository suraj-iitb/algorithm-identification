#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int cnt = 0;
int A[500000];
int L[250001];
int R[250001];

void merge(int A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = A[left + i];
	for (int i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = 1000000000;
	R[n2] = 1000000000;

	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		
		cnt++;
	}
}

void mergeSort(int A[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	mergeSort(A, 0, n);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl << cnt << endl;
}

