#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
using namespace std;
using Int = long long;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<55)+1e9; // ~ 3.6 * 1e16
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
using T = tuple<Int,Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
ostream& operator<<(ostream& o,T t){return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){Int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){Int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

class BIT{
public:
  typedef long long ll;
  ll n;
  vector<ll> bit;
  BIT():n(-1){};
  BIT(ll n_){
    n=1;
    while(n < n_+2) n *= 2;
    bit.resize(n+1, 0);
  }
  
  //[0, i]までの総和を得る
  ll sum(ll i){
    assert( i >= 0 && i <= n );
    i++;
    
    ll s=0;
    while(i>0){
      s = (s + bit[i]);
      i -= i & -i;
    }
    return s;
  }

  //i番目の要素にx加算(0 オリジン)
  void add(ll i,ll x){
    assert( i >= 0 && i <= n );
    i+=2;
    
    while(i <= n){
      bit[i] = (bit[i] + x);
      i += i & -i;
    }
  }
  
  ll sum(Int l,Int r){ //[l, r) 0オリジン
    assert(l <= r);
    assert( 0 <= l && l <= n);
    assert( 0 <= r && r <= n);
    return sum(r) - sum(l);
  }
};


signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  Int n;
  cin>>n;
  vector<Int> A(n);
  cin>>A;

  auto B = A; sort(B.begin(), B.end());
  cout<<B<<endl;

  map<Int,deque<Int> > Idx;
  for(Int i=0;i<n;i++) Idx[A[i]].push_back(i);

  BIT bit(n);
  for(Int i=0;i<n;i++) bit.add(i,1);
  Int ans = 0;
  for(Int i=0;i<n;i++){
    Int idx = Idx[B[i]][0];
    Idx[B[i]].pop_front();
    ans += bit.sum(0,idx);
    bit.add(idx, -1);
  }

  cout<<ans<<endl;
  
  
  
  return 0;
}

