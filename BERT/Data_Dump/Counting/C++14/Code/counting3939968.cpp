#include <bits/stdc++.h>
using namespace std;

void countingSort( vector<int>& a, vector<int>& b, int k ) {
	int n = (int)a.size() - 1;

	vector<int> c( k+1 );
	for( int i = 1; i <= n; ++i ) {
		c[a[i]] += 1;
	}

	for( int i = 1; i <= k; ++i ) {
		c[i] = c[i] + c[i-1];
	}

	for( int i = n; i > 0; --i ) {
		b[c[a[i]]] = a[i];
		c[a[i]] -= 1;
	}
}

int main() {
	ios_base::sync_with_stdio( false );

	int n;
	cin >> n;

	vector<int> a( n+1 );
	for( int i = 1; i <= n; ++i ) {
		cin >> a[i];
	}

	vector<int> b( n+1 );
	countingSort( a, b, 10000 );

	for( int i = 1; i < b.size(); ++i ) {
		cout << b[i] << "\n "[i < b.size()-1];
	}

	return 0;
}

