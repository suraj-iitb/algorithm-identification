#include "bits/stdc++.h"
using namespace std;
using ll = long long; using ull = unsigned long long;
//#define int ll
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<V<T>>;
#define fi first
#define se second
#define maxs(x,y) (x=max(x,y))
#define mins(x,y) (x=min(x,y))
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define eb(val) emplace_back(val)
const double PI = acos(-1), EPS = 1e-10;
const ll MOD = 1e9+7;
void cioacc(){//accelerate cin/cout
  cin.tie(0);
  ios::sync_with_stdio(false);
}
void printvec(const vector<int> &v){
  REP(i,v.size()-1) cout << v[i] <<" ";
  cout << v.back() << endl;
}
void insertion_sort(vector<int> &v,int id){
  int val = v[id];
  int j = id;
  RREP(i,id){
    if(v[i]>val){
      v[i+1] = v[i];
      j = i;
    }else break;
  }
  v[j] = val;
  printvec(v);
}
signed main(){
  int n;
  cin >> n;
  vi a(n);
  REP(i,n) cin >> a[i];
  REP(i,n){
    insertion_sort(a,i);
  }

}

