#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<ll, int>;
using Graph = vector<vector<P>>;

Graph g;

int main(){
  int v, e, r;
  cin >> v >> e >> r;
  g.resize(v);
  for(int i = 0; i < e; ++i){
  	int s, t, d;
  	cin >> s >> t >> d;
  	g[s].push_back({t, d});
  }

  vector<ll> dist(v, LINF);
  priority_queue<P, vector<P>, greater<P>> que;
  dist[r] = 0;
  que.push({dist[r], r});

  while(!que.empty()){
  	auto v = que.top();
  	que.pop();
    int from = v.second;

  	for(auto nv : g[from]){
  		int cost = nv.second;
  		if(dist[from] + cost < dist[nv.first]){
  			dist[nv.first] = dist[from] + cost;
  			que.push({dist[nv.first], nv.first});
  		}
  	}
  }

  for(int i = 0; i < v; ++i){
  	if(dist[i] == LINF){
  		cout << "INF" << endl;
  	}
  	else cout << dist[i] << endl;
  }
  return 0;
}

