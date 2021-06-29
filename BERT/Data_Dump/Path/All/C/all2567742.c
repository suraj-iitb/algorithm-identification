#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
typedef struct ee{
  long long cost,to;
}edge;
int main(){
  int v,e;
  cin>>v>>e;
  vector<vector<ee> >E(v);
  long long dp[v+1][v+1]={};
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      dp[i][j]=INF;
      if(i==j)
	dp[i][j]=0;
    }
  }
  for(int i=0;i<e;i++){
    int a,b,c;
    cin>>a>>b>>c;
    dp[a][b]=c;
  }
  for(int k=0;k<v;k++){
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  int flag=1;
  for(int i=0;i<v;i++){
    if(dp[i][i]<0){
      flag=0;
      cout<<"NEGATIVE CYCLE"<<endl;
      break;
    }
  }
  if(flag){
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
	if(dp[i][j]>=INF-1e10)
	  cout<<"INF";
	else
	  cout<<dp[i][j];
	if(j!=v-1)
	  cout<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
