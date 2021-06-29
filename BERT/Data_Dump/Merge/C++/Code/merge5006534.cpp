
#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1];
  int R[n2 + 1];

  for (int i = 0; i <= n1 - 1; i++) L[i] = A[left + i];
  for (int i = 0; i <= n2 - 1; i++) R[i] = A[mid + i];
  L[n1] = pow(10, 9) + 1;
  R[n2] = pow(10, 9) + 1;

  int i = 0;
  int j = 0;
  for ( int k = left; k <= right-1; k++) {
	  if (L[i] <= R[j]) {
		  A[k] = L[i];
		  i = i + 1;
		  counter++;
	  }	else {
		  A[k] = R[j];
		  j = j + 1;
		  counter++;
	  }
  }
}

void mergeSort(int A[], int left, int right) {
  if (left+1 < right) {
	  int mid = (left + right)/2;
	  mergeSort(A, left, mid);
	  mergeSort(A, mid, right);
	  merge(A, left, mid, right);
  }
}

int main(){
	int n;
	scanf("%d", &n);

	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];

	mergeSort(A, 0, n);

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << A[i] << endl;
		} else {
			cout << A[i] << " ";
		}
	}

	cout << counter << endl;
	return 0;
}

