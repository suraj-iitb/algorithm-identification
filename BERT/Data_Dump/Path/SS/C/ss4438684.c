#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
//Pのfirstは最短距離 secondは頂点
const int INF = 10e8;

struct edge {int to, cost; };
int V, E;
vector<edge> G[100000];
int d[100000];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while(que.size() != 0){
    P p = que.top(); que.pop();
    int v = p.second; // 取り出した頂点
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }

  }
}

int main(){
  int s;
  cin >> V >> E >> s;
  rep(i, E){
    int a, b, c;
    cin >> a >> b >> c;
    edge e = {b, c};
    G[a].push_back(e);
  }
  dijkstra(s);
  rep(i, V){
    if(d[i] == INF){
      cout << "INF";
    }else{
      cout  << d[i];
    }
    cout << endl;
  }
}

