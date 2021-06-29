#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll i, j, n, z;
	
	cin>>n;
	
	vector < ll > a(n+1);
	
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	
	z=0;
	for(i=0; i<n; i++){
		for(j=n-1; j>i; j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				z++;
			}
		}
	}
	
	for(i=0; i<n-1; i++){
		cout<<a[i]<<" ";
	}
	cout<<a[n-1]<<"\n";
	cout<<z<<"\n";
}
