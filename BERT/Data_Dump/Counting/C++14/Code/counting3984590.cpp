#include <bits/stdc++.h>
using namespace std;

void CountingSort(int *A, int *B, int n)
{
	int C[10005] = {};

	for ( int i = 0; i < n; i++ ) {
		C[A[i]]++;
	}

	for ( int i = 1; i <= 10000; i++ ) {
		C[i] += C[i - 1];
	}

	for ( int i = 0; i < n; i++ ) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}	

int main()
{
	int n;
	int A[2000005], B[2000005];
	
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> A[i];
	}
	
	CountingSort(A, B, n);
	cout << B[0];
	for ( int i = 1; i < n; i++ ) {
		cout << " " << B[i];
	}
	cout << endl;
	return ( 0 );
}	
