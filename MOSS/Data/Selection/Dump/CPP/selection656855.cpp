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
		int b = i + 1;
		for ( int t = i + 2; t < n; t++ ) {
			if ( a[b] > a[t] ) b = t;
		}
		if ( a[i] > a[b] ) {
			swap(a[i],a[b]);
			c++;
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
