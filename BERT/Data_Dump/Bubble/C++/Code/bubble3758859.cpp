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
	int flag = 1;
	while( flag ) {
		flag = 0;
		for( int i = N - 1; i > 0; i-- ) {
			if( A[i] < A[i - 1] ) {
				swap( A[i], A[i - 1] );
				flag = 1;
				sw++;
			}
		}
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

