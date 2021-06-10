
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
typedef pair<int, int> P_i;
typedef pair<double,double> P_d;
#define rep(i,n) for(int i=0;i<(n);++i)
#define alrep(i,j,n) for(int i=0;i<(n);++i)for(int j=i+1;j<(n);++j)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;int ans=0;
#define answer cout << ans << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int MOD=1e9+7;
const long long INF = 1LL << 60;

signed main(){
  // 頂点数と辺数
  int N, M; cin >> N >> M;

  int dp[N][N];
  rep(i,N)rep(j,N){
    if(i!=j) dp[i][j]=INF;
    else dp[i][j]=0;
  }
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    dp[a][b]=c;
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  rep(i,N){
    if(dp[i][i]<0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  rep(i,N){
    rep(j,N-1){
      if(dp[i][j]>=INF/2) cout << "INF" << " ";
      else cout << dp[i][j] << " ";
    }
    if(dp[i][N-1]>=INF/2) cout << "INF" << endl;
    else cout << dp[i][N-1] << endl;
  }
  return 0;
}

