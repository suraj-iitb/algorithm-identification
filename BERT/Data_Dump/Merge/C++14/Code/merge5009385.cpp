#include<iostream>
using namespace std;

int L[250002], R[250002];
int cnt;

void merge(int left, int mid, int right, int A[], int n) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = R[n2] = 2000000000;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else if (R[j] < L[i]) {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int A[], int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(left, mid, right, A, n);
	}
}

int main() {
	int X[500000], n;
	cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> X[i];
	}
	mergeSort(X, n, 0, n);

	for (int i = 0; i < n; i++) {
		if (i) {
			cout << " ";
		}
		cout << X[i];
	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}
