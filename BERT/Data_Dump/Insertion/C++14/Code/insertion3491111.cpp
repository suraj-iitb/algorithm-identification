#include <iostream>
#include <vector>
using namespace std;

#define REP( i, n )	for( int i = 0; i < (int)(n); i++ )

int main() {
	int n; cin >> n;
	vector<int> a(n);

	REP( i, n ) cin >> a[i];
	REP( i, n - 1 ) cout << a[i] << " ";
	cout << a[n - 1] << endl;

	for( int i = 1; i < n; i++ ) {
		int tmp = a[i];

		int j;
		for( j = i - 1; j >= 0; j-- ) {
			if( a[j] > tmp ) {
				a[j + 1] = a[j];
			} else {
				break;
			}
		}
		a[j + 1] = tmp;

		REP( i, n - 1 ) cout << a[i] << " ";
		cout << a[n - 1] << endl;
	}

}


