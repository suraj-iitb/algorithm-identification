#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n,A;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		cin>>A;
		a.push_back(A);
	}
	for(int i=0;i<n;i++){
		int v=a[i];
		int j;
		for(j=i-1;j>=0&&a[j]>v;j--) a[j+1]=a[j];
		a[j+1]=v;
		for(j=0;j<n;j++){
			if(j==n-1) cout<<a[j]<<endl;
			else cout<<a[j]<<" ";
		}
	}
	return 0;
}

