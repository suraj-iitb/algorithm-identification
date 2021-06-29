#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} else return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} else return false;}
struct Edge {int to; ll w; Edge(int to, ll w) : to(to), w(w) {}; };
using Graph = vector<vector<Edge>>;
const int INF = 1<<30;
const ll INFL = 1LL<<60;




int main() {
  // 入力受け取り & DP初期条件
  int n, k;
  cin >> n >> k;
  vector<vector<ll>> dp(n, vector<ll>(n, INFL));
  rep(i, k) {
    int s, t;
    ll d;
    cin >> s >> t >> d;
    dp[s][t] = d;
  }
  rep(i, n) dp[i][i] = 0;

  // DP遷移（ワーシャルフロイド）
  rep(k, n) 
    rep(i, n) 
      rep(j, n)
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);  
  
  // dp[v][v] < 0 であれば負閉路が存在
  bool is_negative = false;
  rep(i, n) {
    if (dp[i][i] < 0) is_negative = true;
  }
  if (is_negative) cout << "NEGATIVE CYCLE" << endl;
  else {
    rep(i, n) {
      rep(j, n) {
        if (j) cout << " ";
        if (dp[i][j] >= INFL-1000*1e7) cout << "INF";
        else cout << dp[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
