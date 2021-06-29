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
		int min = i; //??°???????°?????????? 
		for ( int j = i; j < n; j++ ) {
			if ( a[min] > a[j] ) {
				min = j;
			} 
		}
		swap( a[min], a[i] );
		if ( i != min ) swapNum++;
	}
	
	for ( int i = 0; i < n; i++ ) {
		if ( i ) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << swapNum << endl;
	
	return 0;
}
