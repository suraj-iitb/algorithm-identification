#include <iostream>
using namespace std;
int main(){
	int n;
	int a[1000];
	cin >> n;
	for( int i=0 ; i<n ; i++ ){
		cin >> a[i] ;
		cout << a[i];
		if( i!=n-1 )
			cout <<" ";
	}
	cout << endl;
	for( int i=1 ; i<n ; i++ ){
		int v=a[i];
		int j=i-1;
		while(j>=0 && a[j] > v ){
			a[j+1] = a[j];
			j--; 
		}
		a[j+1]=v;
		for( int j=0 ; j<n ; j++ ){
			cout << a[j];
			if( j!=n-1 )
				cout << " ";
		}
		cout << endl;
	}
}
