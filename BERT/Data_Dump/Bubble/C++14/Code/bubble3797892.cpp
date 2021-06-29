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

int bubbleSort( vector<int>& A, int N ) {
	int count = 0;
	bool flag = true;

	while( flag ) {
		flag = false;

		for( int j = N-1; j > 0; --j ) {
			if( A.at( j ) < A.at( j-1 ) ) {
				swap( A.at( j ), A.at( j-1 ) );
				count += 1;
				flag = true;
			}
		}
	}

	return count;
}

int main() {
	int N;
	cin >> N;

	vector<int> a( N );
	for( auto& v: a ) { cin >> v; }

	int count = bubbleSort( a, N );
	print( a );

	cout << count << endl;
}

