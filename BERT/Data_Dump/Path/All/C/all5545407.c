#include <iostream>
#include <vector>
using namespace std;
int main(){
  int nv,ne,s,t;
  long long d;
  cin >> nv >> ne;
  vector<vector<long long>> dp(nv,vector<long long>(nv,1e18));
  for(int i=0;i<nv;i++)
    dp[i][i]=0;
  for(int i=0;i<ne;i++){
    cin >> s >> t >> d;
    dp[s][t]=d;
  }
  for(int k=0;k<nv;k++)
    for(int i=0;i<nv;i++)
      for(int j=0;j<nv;j++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
  for(int i=0;i<nv;i++){
    if(dp[i][i]<0){
      cout << "NEGATIVE CYCLE" << endl;
      exit(0);
    }
  }
  for(int i=0;i<nv;i++){
    for(int j=0;j<nv;j++){
      if(j) cout << " ";
      if(dp[i][j]>1e17){
        cout << "INF";
      } else {
        cout << dp[i][j];
      }
    }
    cout << endl;
  }
}
