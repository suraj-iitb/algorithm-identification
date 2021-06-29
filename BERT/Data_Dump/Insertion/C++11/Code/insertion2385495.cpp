#include <iostream>
using namespace std;

static const int MAX = 100;
int a[MAX];

void Trace(int a[], int len);

int main() {
	
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> a[i];
	}
	Trace(a, n);
	
	for ( int i = 1; i < n; i++ ) {
		int key = a[i]; // ????????\?????°???
		int j = i - 1; // ????????????????°??????? 
		
		while ( j >= 0 && a[j] > key ) { // ??????a[j]>key,a[j]????§???????,j-- 
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		Trace(a, n);
	}
	
	return 0;
}

void Trace(int a[], int len) {
	for ( int i = 0; i < len; i++ ) {
		if ( i ) cout << " ";
		cout << a[i];
	}
	cout << endl;
}
