#include <iostream>
using namespace std;

#define MAX 500000
#define inf 2000000000

int A[MAX];
int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt = 0;

void merge(int A[], int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for ( int i = 0; i < n1; i++ )
		L[i] = A[left + i];
	for ( int i = 0; i < n2; i++ )
		R[i] = A[mid + i];
	L[n1] = inf;
	R[n2] = inf;
	int i = 0, j = 0;
	for ( int k = left; k < right; k++ ) {
		if ( L[i] <= R[j] ) {
			A[k] = L[i++];
			cnt++;
		} else {
			A[k] = R[j++];
			cnt++;
		}
	}
}

void mergesort(int A[], int n, int left, int right) {
	if ( left + 1 < right ) {
		int mid = (left + right)/2;
		mergesort(A, n, left, mid);
		mergesort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}


int main() {
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ )
	 	cin >> A[i];

	mergesort(A, n, 0, n);
	
	for ( int i = 0; i < n; i++ ) {
		if ( i ) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;

	return 0;
}
