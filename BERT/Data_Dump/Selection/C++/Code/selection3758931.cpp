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

int sort( vector<int> &A, int N )
{
	int sw = 0;
	for( int i = 0; i < N; i++ ) {
		int minj = i;
		for( int j = i; j < N; j++ ) {
			if( A[j] < A[minj] ) {
				minj = j;
			}
		}
		if( i != minj ) {
			sw++;
		}
		swap( A[i], A[minj] );
	}
	return sw;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	int sw = sort( A, N );

	print( A, N );
	cout << sw << endl;

}

