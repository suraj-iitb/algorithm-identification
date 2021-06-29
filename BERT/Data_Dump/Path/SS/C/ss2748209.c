// GRL_1_A.cpp
// dijkstra法
#include <bits/stdc++.h>
using namespace std;

const int MAX_V=100000;
const int MAX_E=500000;
const int INF=INT_MAX;

struct E{
  int to,cost;
  E(int t, int c) : to(t),cost(c) {};
};
typedef pair<int,int> pii;

int v;                          // 頂点数
vector<E> g[MAX_V];             // 隣接リスト
int d[MAX_V];                   // 頂点sからの最短距離


void dijkstra(int s){
  // 準備
  fill(d,d+v,INF);
  d[s]=0;
  priority_queue<pii,vector<pii>, greater<pii> > q; // greater<pii>でfirstが小さい順に取り出せるようにする
  q.push(pii(0,s));

  // 頂点ｓから各頂点への最短距離の計算
  while(!q.empty()){
    //　まだ確定していない頂点のうち距離が最小のものを探す
    // その頂点に関しては、最短距離が確定する
    pii p=q.top();
    q.pop();
    int from=p.second;
    if(d[from]<p.first)continue; // 最短距離でなければ無視
    // ここまでくれば頂点fromは最短距離確定

    // 最短距離が確定した頂点に隣接する頂点の情報を更新
    for(int i=0;i<g[from].size();++i){
      int to=g[from][i].to;
      int cost=g[from][i].cost;

      if(d[to]>d[from]+cost){   // 最短距離となりうる場合
        d[to]=d[from]+cost;
        q.push(pii(d[to],to));  // 最短距離の候補をヒープに挿入
      }
    }

  }
}

int main() {
  // 入力
  // gv : 頂点の数
  // ge : 辺の数
  // gr : 始点
  int gv,ge,gr;
  cin>>gv>>ge>>gr;
  v=gv;

  for(int i=0;i<ge;++i){
    // 入力
    // ga : 辺の始点
    // gt : 辺の終点
    // gd : 辺の重み
    int gs,gt,gd;
    cin>>gs>>gt>>gd;
    g[gs].push_back(E(gt,gd));   // 2頂点間の辺の情報を記録
  }

  dijkstra(gr);

  // 出力は、頂点grから各頂点への最短距離
  for(int i=0;i<v;++i){
    if(d[i]!=INF)
      cout<<d[i]<<endl;
    else                        // 頂点iに行けない場合
      cout<< "INF"<<endl;
  }

  return 0;
}

