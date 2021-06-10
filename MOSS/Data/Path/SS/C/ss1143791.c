#include<bits/stdc++.h>

using namespace std;

struct Edge { int src,dst,weight; };

struct Data {
  int cur,weight;
  bool operator < ( const Data &data ) const {
    if( weight != data.weight ) return weight > data.weight;
    return cur > data.cur;
  }
};

const int IINF = INT_MAX;
const int MAX_V = 100010;
int V,E,mindist[MAX_V];
vector<Edge> G[MAX_V];

void dijkstra(int source){
  for(int i=0;i<V;i++) mindist[i] = IINF;
  mindist[source] = 0;
  priority_queue<Data> Q;
  Q.push((Data){source,0});
  while( !Q.empty() ){
    Data data = Q.top(); Q.pop();
    if( mindist[data.cur] < data.weight ) continue;
    for(int i=0;i<(int)G[data.cur].size();i++){
      int next = G[data.cur][i].dst;
      if( mindist[next] > data.weight + G[data.cur][i].weight ){
	mindist[next] = data.weight + G[data.cur][i].weight;
	Q.push((Data){next,mindist[next]});
      }
    }
  }
}

int main(){
  int source;
  cin >> V >> E >> source;
  for(int i=0;i<E;i++){
    int src,dst,weight;
    cin >> src >> dst >> weight;
    G[src].push_back((Edge){src,dst,weight});
    //G[dst].push_back((Edge){dst,src,weight}); // undirected graph
  }
  dijkstra(source);
  for(int i=0;i<V;i++) {
    if( mindist[i] == IINF ) puts("INF");
    else printf("%d\n",mindist[i]);
  }
  return 0;
}
