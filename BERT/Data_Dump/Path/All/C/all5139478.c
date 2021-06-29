#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int INF = INT64_MAX/2;

signed main(){
  int V,E;
  cin>>V>>E;
  vector<vector<int>> G(V,vector<int>(V,INF));
  for(int i=0;i<E;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s][t]=d;
  }

  for(int i=0;i<V;i++){
    G[i][i]=0;
  }

  for(int k=0;k<V;k++){
    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
        if(G[i][k]==INF||G[k][j]==INF) continue;
        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
      }
    }
  }
  bool is_negative=false;
  for(int i=0;i<V;i++){
    if(G[i][i]<0) is_negative=true;
  }
  if(is_negative){
    cout<<"NEGATIVE CYCLE"<<endl;
  }else{
    for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
        if(j)cout<<' ';
        if(G[i][j]==INF) cout<<"INF";
        else cout<<G[i][j];
      }
      cout<<endl;
    }
  }
}
