#include <iostream>
using namespace std;
int main(){
	int n,s[100];
	cin>>n;
	for( int i=0 ; i<n ; i++ ){
		cin >> s[i] ;
	}

	int flag=1;
	int counter=0;
	while(flag){
		flag=0;
		for( int i=n-1 ; i>0 ; i-- ){
			if( s[i] < s[i-1] ){
				swap(s[i],s[i-1]);
				flag=1;
				counter++;
			}
		}
	}
	for( int i=0 ; i<n ; i++ ){
		cout << s[i];
		if( i!=n-1 )
			cout <<" ";
	}
	cout << endl;
	cout << counter << endl;
	return 0;
}
