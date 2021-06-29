#include <bits/stdc++.h>
using namespace std;

typedef int Weight;
struct Edge {  
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : 
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const long long INF=2*1e9;
bool shortestPath(const Graph &g,vector<vector<Weight>> &dist,vector<vector<int>> &inter) {
  int n = g.size();
  dist.assign(n,vector<Weight>(n,INF));
  for(int i=0;i<n;i++) dist[i][i]=0;
  for(int i=0;i<n;i++){
    for(auto f : g[i]) dist[i][f.dst]=f.weight;
  }
  inter.assign(n, vector<int>(n,-1));
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          inter[i][j] = k;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    if(dist[i][i]<0) return false;
  }
  return true;
}

int main(){
	int v, e; cin >> v >> e;
	Graph g(v);
    int s, t, w;
    for(int i=0; i<e; i++){
        cin >> s >> t >> w;
        g[s].push_back({s, t, w});
    }

    vector<vector<Weight>> dist;
    vector<vector<int>> inter; 
    if(!shortestPath(g,dist,inter)){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][j]==INF){
                    cout << "INF";
                }else{
                    cout << dist[i][j];
                }
                if(j!=v-1) cout << " ";
            }
            cout << endl;
        }
    }
}
