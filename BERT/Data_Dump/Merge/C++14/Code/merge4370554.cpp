#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


int merge_cnt(vector<int> &s){
  int n = s.size();
  if (n == 1) return 0;
  int n2 = n/2;

  vector<int> b(n2); rep(i, n2) b[i] = s[i];
  vector<int> c(n-n2); rep(i, n-n2) c[i] = s[i+n2];
  int res = 0;
  res += merge_cnt(b);
  res += merge_cnt(c);
  int bi = 0, ci = 0;
  for (int i=0; i<n; i++){
    if (bi == n2) s[i] = c[ci++];
    else if (ci == n-n2) s[i] = b[bi++];
    else if (b[bi] <= c[ci]) s[i] = b[bi++];
    else s[i] = c[ci++]; res++;
    res++;
  }
  return res;
}

int main() {
  int n; cin >>n;
  vector<int> S(n); rep(i, n) cin >>S[i];
  int res = merge_cnt(S);
  rep(i, n){
    cout <<S[i];
    if (i == n-1) cout <<endl;
    else cout <<" ";
  }
  cout <<res/2 <<endl;
}
