#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const double pi = 3.141592653589793;
#define MOD 1000000007
//#define INF 10000000000000

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P=pair<int,int>;
const int INF=1LL<<60;

/*dijkstra(G,s,dis)
  入力　G　グラフ、s 開始点　dis 距離を格納する
*/
void dijkstra(const Graph &G, int s, vector<int> &dis){
  int n=G.size();//nはノードの数
  dis.resize(n,INF);//スタートから各ノードへの距離をINFで初期化
  priority_queue<P, vector<P>, greater<P>> pq;
  //priority_queue<型、vector<型>、greater<型>>で、値が小さいほうから取り出される
  dis[s]=0;//startまでの距離は０
  pq.emplace(0,s);
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    int v=p.second;
    if(dis[v]<p.first){
      continue;
    }
    for(auto &e:G[v]){
      if(dis[e.to]>dis[v]+e.cost){
        dis[e.to]=dis[v]+e.cost;
        pq.emplace(dis[e.to],e.to);
      }
    }
  }
}
signed main(){
  int v,n,s;
  cin>>v>>n>>s;
  Graph G(v,vector<Edge>(0));

  rep(i,n){
    int t;cin>>t;
    int to,cost;
    cin>>to>>cost;
    G[t].push_back({to,cost});
  }
  vector<int>dis;
  dijkstra(G,s,dis);
  rep(i,v){
    if(dis[i]==INF)cout<<"INF"<<endl;
    else cout<<dis[i]<<endl;
  }
}

