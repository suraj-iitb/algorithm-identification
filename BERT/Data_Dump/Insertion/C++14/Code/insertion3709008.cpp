#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll n,i,key,j;
	
	cin>>n;
	
	vector<ll> a(n+1);
	
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(i=0;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		for(j=0;j<n-1;j++){
			cout<<a[j]<<" ";
		}
		cout<<a[n-1]<<"\n";
	}
}
