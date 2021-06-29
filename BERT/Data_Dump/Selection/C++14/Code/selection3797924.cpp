#include <bits/stdc++.h>
using namespace std;

void print( const vector<int>& a ) {
	size_t n = a.size();

	for( size_t i = 0; i < n; ++i ) {
		cout << a.at( i );

		if( i < n-1 ) { cout << ' '; }
	}

	cout << endl;
}

int selectionSort( vector<int>& A, int N ) {
	int count = 0;

	for( int i = 0; i < N; ++i ) {
		int minj = i;

		for( int j = i; j < N; ++j ) {
			if( A.at( j ) < A.at( minj ) ) {
				minj = j;
			}
		}

		if( i != minj ) {
			swap( A.at( i ), A.at( minj ) );
			count += 1;
		}
	}

	return count;
}

int main() {
	int N;
	cin >> N;

	vector<int> a( N );
	for( auto& v: a ) { cin >> v; }

	int count = selectionSort( a, N );
	print( a );

	cout << count << endl;
}

