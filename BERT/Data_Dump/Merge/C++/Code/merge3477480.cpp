#include <bits/stdc++.h>
using namespace std;

int cnt;

void merge(int *A, int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	int i, j, k;
	for (i = 0; i < n1; i++)
		L[i] = A[left + i];
	L[n1] = INT_MAX;
	for (i = 0; i < n2; i++) 
		R[i] = A[mid + i];
	R[n2] = INT_MAX;
	i = 0; j = 0;
	for (k = left; k < right; k++) 
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		cnt++;
	}
}

void mergeSort(int *A, int left, int right) 
{
	if (left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(void) {
	int n, *A, i;
	cnt = 0;
	cin >> n;
	A = new int[n];
	for (i = 0; i < n; i++) {
		cin >> A[i];
	}
	mergeSort(A, 0, n);
	for (i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;
}
