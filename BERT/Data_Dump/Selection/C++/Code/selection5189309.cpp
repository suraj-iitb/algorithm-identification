#include<iostream>
using namespace std;

int main(){
	int n;
	int mini,temp;
	int noofswap = 0;
	cin >> n;
	int a[n];
	for( int i=0; i<n; i++ ){
		cin >> a[i];
	}
	for( int i=0; i<n; i++ ){
		mini = i;
		for( int j=i+1; j<n; j++ ){
			if(a[j] < a[mini] ){
				mini = j;
			}
		}
		if( i != mini ){
			temp = a[mini];
			a[mini] = a[i];
			a[i] = temp;
			noofswap = noofswap + 1;
		}
	}
	for(int t=0;t<n;t++)
    {
      cout << a[t];    
      if(t != n-1)
       cout << " ";
    }
	cout << endl;
	cout << noofswap << endl;
	return 0;
}
