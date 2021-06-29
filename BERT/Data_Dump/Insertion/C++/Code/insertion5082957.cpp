#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	ll n,num;
	cin>>n;
	ll a[n+1];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	
	for(ll i=0;i<n;i++){
		for(ll j=0;j<i;j++){
			ll temp;
			temp=a[i];
			if(a[i]<a[j]){
				for(ll k=i-1;k>=j;k--)
					a[k+1]=a[k];
				a[j]=temp;
				continue;
		    }
		}
		for(ll h=0;h<n;h++){
			if(h) cout<<" ";
			cout<<a[h];
		}
			cout<<endl;	
	}
}
/*
6
5 2 4 6 1 3
*/
