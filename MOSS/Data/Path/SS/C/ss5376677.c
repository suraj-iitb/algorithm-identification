#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define maxV 100001
#define INF (1e9 + 1)

int main(){
  int V,E,r,a,b,c;
  vector<int> G_t[maxV];
  vector<int> G_c[maxV];

  int d[maxV];
  cin >> V >> E >> r;
  for(int i=0; i<E; i++){
    cin >> a >> b >> c;
    G_t[a].push_back(b);
    G_c[a].push_back(c);
  }
  // dijkstra;
  for(int i=0; i<maxV; i++){
    d[i]=INF;
  } d[r]=0;

  priority_queue< pair<int,int> > Q;
  Q.push(make_pair(-d[r],r));
  while(!Q.empty()){
    pair<int ,int > p=Q.top();
    Q.pop();
    int pos = p.second, cost = -p.first;
    if(cost > d[pos]) continue;
    for(int i=0; i<G_t[pos].size(); i++){
      int to = G_t[pos][i];
      int newCost = cost + G_c[pos][i];
      if(newCost < d[to]){
        d[to] = newCost;
        Q.push(make_pair(-d[to],to));
      }
    }
  }
  for(int i=0; i<V; i++){
    if(d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
  return 0;
}
