#include <bits/stdc++.h>
using namespace std;

void print( vector<int> &A, int N )
{
	for( int k = 0; k < N; k++ ) {
		cout << A[k];
		if( k < N - 1 ) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
}

void sort( vector<int> &A, int N )
{
	for( int i = 1; i < N; i++ ) {
		int v = A[i];
		int j = i - 1;
		while( j >= 0 && A[j] > v ) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		print( A, N );
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	print( A, N );

	sort( A, N );
}

