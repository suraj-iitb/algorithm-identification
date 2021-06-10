#include <bits/stdc++.h>

using namespace std;

#define MAX_V 100000
#define INF 1e9
typedef pair<int,int> pii;

struct edge{
  int to,d;
};

int V,E;
int weight[MAX_V];
vector<edge> G[MAX_V];

void dijkstra(int r){
  priority_queue<pii,vector<pii>,greater<pii> > Q;
  Q.push(pii(0,r));
  weight[r] = 0;
  while(!Q.empty()){
    pii p = Q.top(); Q.pop();
    int v = p.second;
    if(weight[v] < p.first){ continue; }
    for(int i = 0 ; i < (int)G[v].size() ; i++){
      edge &e = G[v][i];
      if(weight[v] + e.d < weight[e.to]){
        weight[e.to] = weight[v] + e.d;
        Q.push(pii(weight[e.to],e.to));
      }
    }
  }
}

void init(){
  for(int i = 0 ; i < MAX_V ; i++){
    G[i].clear();
    weight[i] = INF;
  }
}

int main(){
  int r,s,t,d; init();
  cin >> V >> E >> r;
  for(int i = 0 ; i < E ; i++){
    cin >> s >> t >> d;
    G[s].push_back((edge){t,d});
  }
  dijkstra(r);
  for(int i = 0 ; i < V ; i++){
    if(weight[i] == INF){
      cout << "INF" << endl;
    }else{
      cout << weight[i] << endl;
    }
  }
  return 0;
}
