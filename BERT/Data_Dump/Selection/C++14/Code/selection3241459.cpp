#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define eps LDBL_EPSILON
#define int long long
//#define double long double
#define moder 1000000007
#define P std::pair<int,int>
using namespace std;

int n,a[110];
int selectionsort(){
	int ans=0;
	rep(i,n){
		int minj=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj])minj=j;
		}
		swap(a[i],a[minj]);
		if(i!=minj)ans++;
	}
	return ans;
}
signed main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	int ans=selectionsort();
	rep(i,n-1)cout<<a[i]<<" ";
	cout<<a[n-1]<<endl<<ans<<endl;
	return 0;
}
