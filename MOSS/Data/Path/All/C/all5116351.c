#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1e17;

void warshall_floyd(vector<vector<ll>> &dist){
  int V=dist.size();
  for(int k=0;k<V;++k){
    for(int i=0;i<V;++i){
      for(int j=0;j<V;++j){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}

bool is_negative(const vector<vector<ll>> &dist){
  int V=dist.size();
  for(int i=0;i<V;++i){
    if(dist[i][i]<0)return true;
  }
  return false;
}



int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<ll>> dist(v,vector<ll>(v,INF));
  for(int i=0;i<v;++i)dist[i][i]=0;
  for(int i=0;i<e;++i){
    ll s,t,d;
    cin >> s >> t >> d;
    dist[s][t]=d;
  }
  warshall_floyd(dist);

  if(is_negative(dist)){
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }


  for(int i=0;i<v;++i){
    for(int j=0;j<v;++j){
      if(dist[i][j]>=INF/2){
        cout << "INF";
      }else{
        cout << dist[i][j];
      }
      if(j==v-1)cout << endl;
      else cout << " ";
    }
  }
}

