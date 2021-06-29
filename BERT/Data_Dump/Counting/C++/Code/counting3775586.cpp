#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> A( n + 1 );
	vector<int> B( n + 1 );
	for( int i = 1; i < n + 1; i++ ) {
		cin >> A[i];
	}

	int k = 10000 + 1;
	vector<int> C( k );
	for( int i = 1; i < n + 1; i++ ) {
		C[ A[i] ]++;
	}
	for( int i = 1; i < k + 1; i++ ) {
		C[i] += C[i - 1];
	}
	for( int i = n; i > 0; i-- ) {
		B[ C[ A[i] ] ] = A[i];
		C[ A[i] ]--;
	}
	for( int i = 1; i < n + 1; i++ ) {
		if( i > 1 ) cout << " ";
		cout << B[i];
	}
	cout << endl;
}

