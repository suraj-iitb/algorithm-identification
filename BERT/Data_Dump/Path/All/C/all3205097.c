#include<bits/stdc++.h>

using namespace std;

constexpr long long INF64 = 1e18;

class Graph {
  std::vector<std::vector<long long>> dist;

  bool flag = false;

  void WarshallFloyd() {
    const int n = dist.size();
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
             if(dist[i][k]!=INF64 && dist[k][j]!=INF64){
                dist[i][j] = dist[i][k] + dist[k][j];
             }
          }
        }
      }
    }
    flag = true;
  }

public:
  Graph(int n)
      : dist(n, std::vector<long long>(n,INF64)) {
        for(int i=0;i<n;++i){
            dist[i][i]=0;
        }
      }

  void addEdge(int s, int t, long long cost) {
    dist[s][t] = std::min(dist[s][t], cost);
    flag = false;
  }
    
  bool onNegativeCycle(int i){
      if (!flag) {
        WarshallFloyd();
      }
      if(dist[i][i]<0)return true;
      else return false;
  }
      
  long long getCost(int s, int t) {
    assert(!onNegativeCycle(s) && !onNegativeCycle(t));
    if (!flag) {
      WarshallFloyd();
    }
    return dist[s][t];
  }
};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;++i){
        int from,to;
        long long weight;
        cin>>from>>to;
        cin>>weight;
        g.addEdge(from,to,weight);
    }
    for(int i=0;i<n;++i){
        if(g.onNegativeCycle(i)){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            long long ans=g.getCost(i,j);
            if(ans==INF64)cout<<"INF";
            else cout<<ans;
            if(j<n-1)cout<<" ";
            else cout<<endl;
        }
    }
}
        
