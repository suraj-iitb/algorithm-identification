#include <vector>
#include <iostream>
using namespace std;

int main(){
	int n;
	int b;
	cin >> n;
	vector<int> a;
	for (int i=0 ;i<n ;i++ ) {
		a.push_back(i);
		cin >> a[i];
	}
	for (int i=0 ;i<n ;i++ ) {
		for (int t=i-1 ;t>=0 ;t-- ) {
			if ( a[t] <= a[t+1] ) break;
			b = a[t];
			a[t] = a[t+1];
			a[t+1] = b;
		}
		for (int t=0 ;t<n ;t++ ) {
			cout << a[t];
			if ( t < n-1 ) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
