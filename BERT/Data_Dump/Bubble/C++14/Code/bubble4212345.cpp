#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++) 
#define rep(i,n); for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b); 
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e10+10;

/*----------------------------------------------*/

signed main(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,n) cin>>a[i];
  bool flag=true;
  int ans=0;
  while(flag){
    flag=false;
    for(int j=n-1;j>0;j--){
      if(a[j-1]>a[j]){
        int v=a[j-1];
        a[j-1]=a[j];
        a[j]=v;
        flag=1;ans++;
      }
    }
  }
  rep(i,n-1)cout<<a[i]<<" ";
  cout<<a[n-1]<<endl;
  cout<<ans<<endl;

  return 0;
}
