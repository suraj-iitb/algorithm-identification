#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		sort(a,a+i);
		for(int j=0;j<n;j++){
			cout<<a[j];
			if(j!=n-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
