#include <bits/stdc++.h>
using namespace std;

void print( const vector<int>& a ) {
	int n = a.size();

	for( int i = 0; i < n; ++i ) {
		cout << a.at( i );

		if( i < n-1 ) { cout << ' '; }
	}

	cout << endl;
}

void insertionSort( vector<int>& A, int N ) {
	print( A );

	for( int i = 1; i < N; ++i ) {
		int v = A.at( i );
		int j = i - 1;

		while( j >= 0 && A.at( j ) > v ) {
			A.at( j+1 ) = A.at( j );
			j -= 1;
		}

		A.at( j+1 ) = v;

		print( A );
	}
}

int main() {
	int N;
	cin >> N;

	vector<int> A( N );
	for( auto& v: A ) { cin >> v; }

	insertionSort( A, N );
}

