#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

#define REP( i, n )	for( int (i) = 0; (i) < (n); (i)++ )

int main() {
	int n; cin >> n;

	vector<int> a(n);
	REP( i, n ) cin >> a[i];

	int count = 0;
	REP( i, n - 1 ) {
		int min = a[i];
		int p = i;
		for( int j = i + 1; j < n; j++ ) {
			if( a[j] < min ) {
				min = a[j];
				p = j;
			}
		}
		if( p != i ) {
			a[p] = a[i];
			a[i] = min;
			count++;
		}
	}

	REP( i, n - 1 ) cout << a[i] << " ";
	cout << a[n - 1] << endl << count << endl; 
}
