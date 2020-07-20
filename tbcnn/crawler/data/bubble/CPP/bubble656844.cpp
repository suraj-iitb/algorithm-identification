#include <vector>
#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a;
	int c = 0;
	for ( int i = 0; i < n; i++ ) {
		a.push_back(i);
		cin >> a[i];
	}
	for ( int i = 0; i < n - 1; i++ ) {
		for ( int t = n - 2; t >= i; t-- ) {
			if ( a[t] > a[t+1] ) {
				int b;
				b = a[t];
				a[t] = a[t+1];
				a[t+1] = b;
				c++;
			}
		}
	}
	for ( int i = 0; i < n; i++ ) {
		cout << a[i];
		if ( i < n - 1 ) {
			cout << " ";
		}else {
			cout << endl;
		}
	}
	cout << c << endl;
	return 0;
}
