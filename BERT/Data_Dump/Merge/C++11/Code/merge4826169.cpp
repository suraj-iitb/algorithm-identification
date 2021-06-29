#include<bits/stdc++.h>

using namespace std;

const int maxn = 500000 + 2;
const int SENTINEL = 2000000000;
int A[maxn], L[maxn / 2 + 2], R[maxn / 2 + 2];
int cnt = 0;
int n;
void merge(int A[], int n, int l,int mid, int r) {
	int n1 = mid - l;
	int n2 = r - mid;
	for (int i = 0; i < n1; ++i)L[i] = A[l + i];
	for (int i = 0; i < n2; ++i)R[i] = A[mid + i];
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	int i = 0, j = 0;
	for (int k = l; k < r; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}
void show(int A[]) {
	for (int i = 0; i < n; ++i) {
		cout << A[i];
		if(i < n - 1)cout << " ";
	}
	printf("\n");
}

void mergeSort(int A[],int n, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, n,left, mid);
		mergeSort(A, n,mid, right);
		merge(A, n, left, mid,right);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	mergeSort(A, n,  0, n);
	show(A);

	cout << cnt << endl;


	return 0;
}
