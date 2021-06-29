#include<bits/stdc++.h>
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<long long> vlong;
#define vpush(a,x) a.push_back(x);
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
  	int n;
  	cin>>n;
  	vint a(n);
	rep(i,n){
      	cin>>a[i];
    }
  	sort(all(a));
  	rep(i,n){
      cout<<a[i];
      if(i!=n-1){
        cout<<' ';
      }
      else{
        cout<<'\n';
      }
    }
    return(0);
}
