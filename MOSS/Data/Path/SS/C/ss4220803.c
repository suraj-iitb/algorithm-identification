#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, E, r; cin >> N >> E >> r;
  vector<vector<pair<int, int> > > G(N, vector<pair<int, int> >());
  REP(i, E){
    int s, t, d; cin >> s >> t >> d;
    G[s].push_back({d, t});
  }
  int INF = 1001001001;
  vector<int> cost(N, INF);
  vector<bool> check(N, false);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  cost[r] = 0; check[r] = true;
  for(auto &i : G[r]){
    pq.push(i);
  }
  while(!pq.empty()){
    auto p = pq.top(); pq.pop();
    int d = p.first, t = p.second;
    if(check[t]) continue;
    cost[t] = d; check[t] = true;
    for(auto &i : G[t]){
      pq.push({i.first+d, i.second});
    }
  }
  REP(i, N){
    if(cost[i] == INF){
      cout << "INF" << endl;
    }else{
      cout << cost[i] << endl;
    }
  }
}
