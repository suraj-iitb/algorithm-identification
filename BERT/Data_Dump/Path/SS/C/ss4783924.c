#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

//エッジ数，頂点数
int E, V;

//行き先とそのコスト
struct Edge{
  int to;
  int cost;
};

using Graph = vector<vector<Edge> >;
using P = pair<int, int>;

void dijkstra(Graph G, int s, int *dis){
  int N = G.size();

  //INFで書き換え
  rep(i, V)
    dis[i] = 1000000000;
  
  //頂点firstへの最短経路がsecondであるpair型のpriority queue 
  priority_queue<P, vector<P>, greater<P>> pq;

  //sからsへの最短経路は0
  dis[s] = 0;
  pq.emplace(dis[s], s);

  //キューが空でない限り続ける
  while(!pq.empty() ){
    //先頭のペア
    P p = pq.top();
    pq.pop();

    int now = p.second;

    //最短距離でなければ無視
    if(dis[now] < p.first)
      continue;
    
    for(auto e : G[now]){
      //最短距離候補である
      if(dis[e.to] > dis[now] + e.cost){
	//最短経路の更新
	dis[e.to] = dis[now]+e.cost;
	//priority queueに突っ込む
	pq.emplace(dis[e.to], e.to);
      } // if
    } // for
  } // while
} // dijkstra

int main(){
  int r;
  cin >> V >> E >> r;
  int s[E], t[E], d[E];
  rep(i, E){
    cin >> s[i] >> t[i] >> d[i];
  }
  //入力終了

  Graph G(V);
  
  //グラフの作成
  rep(i, E){
    Edge tmp;
    tmp.to = t[i];
    tmp.cost = d[i];
    G[s[i] ].push_back(tmp);
  }

  //ダイクストラ
  dijkstra(G, r, d);

  rep(i, V)
    if(d[i] == 1000000000)
      cout << "INF" << endl;
    else
      cout << d[i] << endl;

  return 0;
}
