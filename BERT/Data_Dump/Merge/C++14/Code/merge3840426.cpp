#include <bits/stdc++.h>
using namespace std;

void print( const vector<int>& a, char sep = ' ' ) {
	size_t n = a.size();

	for( size_t i = 0; i < n; ++i ) {
		cout << a.at( i );

		if( i < n-1 ) { cout << sep; }
	}

	cout << endl;
}

int merge( vector<int>& a, int left, int mid, int right ) {
	int n1 = mid - left;
	int n2 = right - mid;

	vector<int> L( a.begin()+left, a.begin()+left + n1 );
	vector<int> R( a.begin()+mid,  a.begin()+mid  + n2 );
	L.push_back( INT_MAX ); // inf
	R.push_back( INT_MAX );

	int count = 0;
	int i = 0;
	int j = 0;

	for( int k = left; k < right; ++k ) {
		a[k] = L[i] <= R[j] ? L[i++] : R[j++];

		count += 1;
	}

	return count;
}

int mergeSort( vector<int>& a, int left, int right ) {
	int r = 0;

	if( left+1 < right ) {
		int mid = (left + right) / 2;

		r += mergeSort( a, left, mid );
		r += mergeSort( a, mid, right );
		r += merge( a, left, mid, right );
	}

	return r;
}

int main() {
	ios_base::sync_with_stdio( false );

	int n;
	cin >> n;

	vector<int> S( n );
	for( auto& v: S ) { cin >> v; }

	int count = mergeSort( S, 0, n );

	print( S );
	cout << count << endl;
}

