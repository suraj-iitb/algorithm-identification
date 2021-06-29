#include<bits/stdc++.h>
using namespace std;
int c[100000] = {};
int main(){
	int n;
	cin>>n;
	int t[n];
	for(int  i= 0;i<n;i++){
		cin>>t[i];
	}
	for(int i = 0;i<n;i++){
		c[t[i]]++;
	}
	int j = 0,p = 0;
	for(int i = 0;i<100000;i++){
		for(int j = c[i];j>0;j--){
			if(p >= n-1){
				cout<<i<<endl;
				break;
			}
			cout<<i<<" ";
			c[i]--;
			p++;
		}
	}
}
