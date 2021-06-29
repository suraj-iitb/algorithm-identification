#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
int main(void){

	int n, v, j;
	int a[100];
	cin >> n;
	for( int i = 0; i < n; i++ ){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if( i < n - 1 ){
			cout << " ";
		}
	}
	cout << endl;
	for( int i = 1; i < n; i++ ){
		v = a[i];
		j = i - 1;
		while( j >= 0 && a[j] > v ){
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = v;
		for (int i = 0; i < n; i++) {
			cout << a[i];
			if( i < n - 1 ){
				cout << " ";
			}
		}
	cout << endl;
	}
	return 0;
}
