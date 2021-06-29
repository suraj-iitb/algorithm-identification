#include<bits/stdc++.h>
  
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed fixed<<setprecision(14)
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
const lol inf=(1LL<<60);
const lol Mod=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
bool line(lol x,lol y,lol nx,lol ny){return (x<nx&&y<ny&&x>=0&&y>=0);}
lol n,m,k,r;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  lol ans=0;
  cin >>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >>a[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
        ans++;
      }
    }
  }
  for(int i=0;i<n-1;i++) cout <<a[i]<<' ';
  cout <<a.back()<<'\n';
  cout <<ans<<'\n';
  return (0);
}

