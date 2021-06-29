#include<bits/stdc++.h>
using namespace std;
/*#define mod 1000000007
//#define int long long int
#define INF 1e9+100
#define pair<int,int> pii
#define ff first
#define ss second
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define fi(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define pb push_back
#define  debug(x)  cout<<#x<<" "<<x<<endl;*/
int main()
{
	int n,i,j,k;
	cin>>n;
	int a[n+3];
	int val;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++)
	{
		j=i-1;
		val=a[i];
		while(j>=0 and a[j]>val)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=val;
		for(k=0;k<n-1;k++) cout<<a[k]<<" ";
		cout<<a[n-1];
		cout<<endl;
	}
}

