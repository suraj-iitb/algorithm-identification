#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,a,b) for(int i = (a); i < (b); i++)
#define MOD 1000000007
#define inf 2e9+5

long v,e;
//vector<vector<long>> dp(100,vector<long>(100,inf));
//vector<vector<long>> dp;
long dp[100][100];
int main(void) {
  long s,t,d;
  cin >> v >> e;
  rep(i,v)rep(j,v) dp[i][j]=inf;
  rep(i,v) dp[i][i]=0;
  rep(i,e) {
    cin >> s >> t >> d;
    dp[s][t]=min(dp[s][t],d); //s-->t
  }
  for(int k=0; k<v; k++) {
    for(int i=0; i<v; i++) {
      if(dp[i][k]==inf) continue; //重要！！！
      for(int j=0; j<v; j++) {
         if(dp[k][j]==inf) continue; //重要！！！
      dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  //negative cycle or not
  bool key=false;
  rep(i,v) if(dp[i][i]<0) key=true;
  if(key) {cout << "NEGATIVE CYCLE" << endl; return 0;}
  //v==1 or not
  if(v==1) {cout << 0 << endl; return 0;}
  rep(i,v) rep(j,v) {
    if(dp[i][j]==inf) {
      if(j==0) printf("INF");
      else if(j==v-1) printf(" INF\n");
      else printf(" INF");
    } else {
      if(j==0) printf("%ld",dp[i][j]);
      else if(j==v-1) printf(" %ld\n",dp[i][j]);
      else printf(" %ld",dp[i][j]);
    }
  }
}
