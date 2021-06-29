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
  int sw=0;
  rep(i,n){
    int minj=i;
    FOR(j,i,n-1){
      if(a[j]<a[minj]) minj=j;
    }
    if(minj!=i){
      int v=a[i];
      a[i]=a[minj];
      a[minj]=v;
      sw++;
    }
  }
  rep(i,n){
    if(i) cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<sw<<endl;
  return 0;
}
