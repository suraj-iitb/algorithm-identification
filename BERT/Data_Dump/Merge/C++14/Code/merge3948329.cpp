#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using Int = unsigned long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
static int const mod = 1e9+7;
#define END {cout<<(ans)<<'\n'; return 0;}
#define ALL(vec) vec.begin(),vec.end()
#define Pr(type) priority_queue<type>
#define gPr(type) priority_queue<type,vector<type>,greater<type>>
#define V(type) vector<type>
#define rep(i,n) for(int i=0; i<n; i++)
#define rer(i,s,n) for(int i=s; i<=n; i++)
#define gnr(i,l,r) for(int i=r; i>=l; i--)
#define eb emplace_back
#define fi first
#define se second
#define pri1(a) cout<<(a)<<'\n'
#define pri2(a,n) rep(i,(n)-1)cout<<a[i]<<' '; if(n)cout<<a[(n)-1]<<'\n';
#define prip(p) cout<<(p).first<<' '<<(p).second<<'\n'
template<class T> inline bool cmin(T& a, T b) { if (a > b) { return a = b; } return false; }
template<class T> inline bool cmax(T& a, T b) { if (a < b) { return a = b; } return false; }

Int n,m,q,_,x,y;
string s,sb;
bool ok;
char ch;

void merge(vector<int> &vec,int l,int mid,int r){
  int ll=mid-l,rl=r-mid; V(int)la(ll+1,mod),ra(rl+1,mod);
  rep(i,ll)la[i]=vec[l+i];
  rep(i,rl)ra[i]=vec[mid+i];
  int i=0,j=0;
  rer(k,l,r-1){
    x++;
    if(la[i]<=ra[j]){
      vec[k]=la[i];
      i+=1;
    }else{
      vec[k]=ra[j];
      j+=1;
    }
  }
}

void mergeSort(vector<int> &vec,int l,int r){
  if(l+1<r){
  int mid=(l+r)/2;
  mergeSort(vec,l,mid);
  mergeSort(vec,mid,r);
  merge(vec,l,mid,r);}
  return;
}

int main(){
  cin.tie(nullptr); ios::sync_with_stdio(0);

  cin>>n; V(int) a(n); rep(i,n)cin>>a[i];
  mergeSort(a,0,n);
  pri2(a,n);
  pri1(x);
}
