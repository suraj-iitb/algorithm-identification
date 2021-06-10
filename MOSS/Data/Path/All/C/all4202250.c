#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define REPR(i, m, n) for (int i = (int)(m); i >= (int)(n); i--)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

static const int MAX = 100;
static const long long INF = (1LL<<32);

int n;
long long d[MAX][MAX];

void floyd(){
  rep(k, n){
    rep(i, n) if(d[i][k] != INF){
      rep(j, n) if(d[k][j] != INF){
        chmin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
  int e;
  cin >> n >> e;

  rep(i, n){
    rep(j, n){
      if(i == j) d[i][j] = 0;
      else d[i][j] = INF;
    }
  }

  rep(i, e){
    int u, v, c;
    cin >> u >> v >> c;
    d[u][v] = c;
  }

  floyd();

  bool negative = false;
  rep(i, n) if(d[i][i] < 0) negative = true;

  if(negative){
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  else{
    rep(i, n){
      rep(j, n){
        if(j) cout << " ";
        if(d[i][j] == INF) cout << "INF";
        else cout << d[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}



