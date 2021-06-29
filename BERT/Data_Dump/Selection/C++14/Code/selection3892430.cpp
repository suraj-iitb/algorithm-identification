#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
int const MOD = 1000000007;
#define END {cout<<END<<'\n'; return 0;}
#define ALL(vec) vec.begin(),vec.end()
#define Pr(type) priority_queue<type>
#define gPr(type) priority_queue<type,vector<type>,greater<type>>
#define V(type) vector<type>
#define rep(i,n) for(int i=0; i<n; i++)
#define rer(i,s,n) for(int i=s; i<n; i++)
#define gnr(i,l,r) for(int i=r; i>=l; i--)
#define eb emplace_back
#define pri1(a) cout<<a<<'\n'
#define pri2(a,n) rep(i,n-1)cout<<a[i]<<' '; cout<<a[n-1]<<'\n';
template<class T> inline bool cmin(T& a, T b) { if (a > b) { return a = b; } return false; }
template<class T> inline bool cmax(T& a, T b) { if (a < b) { return a = b; } return false; }

int n,m,q,_,x,y;
string s,t;
bool ok;

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
    
  cin>>n; V(int)a(n); rep(i,n)cin>>a[i];
  rep(i,n){
    m=i;
    rer(j,i+1,n)if(a[j]<a[m])m=j;
    swap(a[i],a[m]);
    if(i!=m)q++;
  }
  pri2(a,n); pri1(q);
}
