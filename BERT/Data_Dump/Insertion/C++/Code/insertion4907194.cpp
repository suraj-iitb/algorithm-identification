#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	
	for(int i=0;i<n;i++){	
		int take=a[i];
		int j=i;
		for(;j>0&&a[j-1]>take;j--){
			a[j]=a[j-1];
		}
		a[j]=take;
		for(int k=0;k<n;k++){
			cout << a[k];
			if(k!=n-1) cout << ' ';
			else cout << '\n';
		}
		
	}	
	return 0;
}
//6 5 4 3 2 1
//5 6 3 4 2 1
