#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n,A,ans=0;
	bool flag=true;
	vector<int> a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A;
		a.push_back(A);
	}
	while(flag){
		flag=false;
		for(int i=n-1;i>0;i--){
			if(a[i]<a[i-1]){
				int tmp=a[i-1];
				a[i-1]=a[i];
				a[i]=tmp;
				flag=true;
				ans++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i==n-1) cout<<a[i]<<endl<<ans<<endl;
		else cout<<a[i]<<" ";
	}
	return 0;
}

