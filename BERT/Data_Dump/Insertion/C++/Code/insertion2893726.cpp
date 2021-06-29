#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,to) for(int i=x;i<to;i++) 

int main() {
	int n,a[100]={};
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
	}
	rep(i,0,n){
		int v = a[i];
		int j = i-1;
		while(j>=0&&a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		rep(j,0,n){
			if(j==n-1) cout << a[j] << endl;
			else cout << a[j] << " ";
		}
	}
	return 0;
}
