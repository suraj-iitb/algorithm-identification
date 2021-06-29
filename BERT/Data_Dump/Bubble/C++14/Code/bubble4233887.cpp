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
  int t;
  int m;
  cin>>n;
  int a[n+3];
  for(i=0;i<n;i++) cin>>a[i];
  int cnt=0;
  for(i=0;i<n-1;i++)
  {
  	for(j=0;j<n-1-i;j++)
	{
		if(a[j]>a[j+1])
		{
			a[j]+=a[j+1];
			a[j+1]=a[j]-a[j+1];
			a[j]=a[j]-a[j+1];
			cnt++;
		}
	}
  }
  for(i=0;i<n-1;i++) cout<<a[i]<<" ";
  cout<<a[n-1];
  cout<<endl;
  cout<<cnt<<endl;
}

