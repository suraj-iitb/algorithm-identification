#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll MOD = 1000000007;
ll INF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------

ll n; // 頂点数
vvll dist;
bool negatine = false;

void init(){
  dist.resize(n,vll(n));
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < n; j++){
      dist[i][j] = (i == j ? 0 : INF);
    }
  }
}

void warshall_floyd(){
  for(ll k = 0; k < n; k++){
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
        if(dist[i][k] != INF && dist[k][j] != INF){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  for(ll i = 0; i < n; i++){
    if(dist[i][i] < 0) negatine = true;
  }
}

//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> n;
  init();
  ll m;
  cin >> m;
  REP(i,m){
    ll s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  warshall_floyd();

  if(negatine) cout << "NEGATIVE CYCLE" << endl;
  else{
    REP(i,n){
      REP(j,n){
        if(j) cout << " ";
        if(dist[i][j] == INF) cout << "INF";
        else cout << dist[i][j];
      }
      cout << endl;
    }
  }
  

  return 0;
}


