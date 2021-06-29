#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

#define REP( i, n )	for( int (i) = 0; (i) < (n); i++ )

int main() {
	int n; cin >> n;

	vector<int> a(n);
	REP( i, n ) cin >> a[i];

	int count = 0;
	REP( i, n - 1 ) {
		for( int j = n - 1; j > i; j-- ) {
			if( a[j - 1] > a[j] ) {
				swap( a[j - 1], a[j] );
				count++;
			}
		}
	}

	REP( i, n - 1 ) cout << a[i] << " ";
	cout << a[n - 1] << endl << count << endl; 
}
