#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<ll, int> P;

struct edge { int to, cost; };

const ll INF = 1e15;
const ll MAX_V = 100000;

int V, E;
int s;

vector<edge> G[MAX_V];
ll d[MAX_V];

//??????????????\?????????????????????????????????
void dijkstra(int s){
  priority_queue< P, vector<P>, greater<P> > que;
  rep(i, V) d[i] = INF;
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int stand_v = p.second;
    if(p.first > d[stand_v]) continue; //?????§??????????????????????????§?????£???
    rep(i, G[stand_v].size()){
      edge e = G[stand_v][i];
      if(d[stand_v] + e.cost < d[e.to]){
	d[e.to] = d[stand_v] + e.cost;
	que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  cin >> V >> E >> s;
  rep(i, E){
    int tmp_s, tmp_t, tmp_d;
    cin >> tmp_s >> tmp_t >> tmp_d;
    G[tmp_s].push_back((edge){tmp_t, tmp_d});
  }

  dijkstra(s);

  rep(i, V){
    if(d[i] < INF) cout << d[i] << endl;
    else cout << "INF" << endl;
  }

  return 0;
}
