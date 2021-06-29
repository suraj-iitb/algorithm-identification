#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, n) for (int i = (int)(l); i < (int)(n); i++)
#define drep(i, n) for (int i = (int)(n); i > 0; i--)
#define INF (pow(10,12))
#define def (200007)
#define MOD (1000000007)
typedef vector<int> veci;
typedef vector<vector<int>> Veci;
typedef vector<int64_t> vecit;
typedef vector<vector<int64_t>> Vecit;
typedef int64_t intt;
typedef vector<vector<double>> Vecd;
typedef vector<double> vecd;
typedef pair<int, int> P;
/*veci のときdist.resize(N) Veciのとき2回resize;
dp.assign(N,-1);*/

int main(){
  int V,E;cin>>V>>E;
  Vecit dp(V,vecit(V,INF));
  rep(i,0,E){
    int s,t,d;cin>>s>>t>>d;
    dp[s][t]=d;
  }
  rep(k,0,V){
    rep(i,0,V){
      rep(j,0,V){
        if(!(dp[i][k]==INF || dp[k][j]==INF)){
          dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
        }
      }
    }
  }
  int judge=0;
  rep(i,0,V){
	if(dp[i][i]<0)judge=1;
  }
  if(!judge){
    rep(i,0,V){
      rep(j,0,V){
        if(i==j && dp[i][j]>=0)cout<<"0";
        else if(dp[i][j]==INF)cout<<"INF";
        else cout<<dp[i][j];
        if(j!=V-1)cout<<" ";
      }cout<<endl;
    }
  }else cout<<"NEGATIVE CYCLE"<<endl;
  return 0;
}
