#include <iostream> 
using namespace std;

static const int MAX = 100;
int a[MAX];

int main() {
	
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	
	int swapNum = 0;
	for ( int i = 0; i < n-1; i++ ) {
		for ( int j = n-1; j > i; j-- ) {
			if ( a[j] < a[j-1] ) {
				swap( a[j], a[j-1] );
				swapNum++;
			}
		}
	}
	
	for ( int i = 0; i < n; i++ ) {
		if ( i ) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << swapNum << endl;
	
	return 0;
} 
