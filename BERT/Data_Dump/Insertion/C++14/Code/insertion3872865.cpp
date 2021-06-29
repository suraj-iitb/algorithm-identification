#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
const int mod = 1e9+7;
#define END {cout<<ans<<'\n'; return 0;}
#define ALL(v) v.begin(),v.end()
#define Pr(type) priority_queue<type>
#define gPr(type) priority_queue<type,vector<type>,greater<type>>
#define V(type) vector<type>
#define rep(i,n) for(int i=0; i<n; i++)
#define rer(i,st,en) for(int i=st; i<=en; i++)
#define eb emplace_back
#define pri1(a) cout<<a<<'\n'
#define pri2(a,n) rep(i,n)cout<<a[i]<<'\n'
#define pri3(a,n) rep(i,n)cout<<a[i]<<(i!=n-1?' ':'\n')
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int n,m,_,x,y,q;
string s;

int main(){
  cin.tie(nullptr); ios::sync_with_stdio(false);

  cin>>n; int a[n]; rep(i,n)cin>>a[i];
  rer(i,1,n){
    m=i; pri3(a,n);
    while(m&&a[m-1]>a[m]){
      swap(a[m-1],a[m]); m--;
    }
  }
}
