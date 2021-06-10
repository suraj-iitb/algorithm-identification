#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll V, E, r;  cin >> V >> E >> r;
  vector<vector<pair<ll, ll>>> map(V);
  rep(i, E) {
    ll s, t, d; cin >> s >> t >> d;
    map[s].push_back(make_pair(t, d));
//    map[t].push_back(make_pair(s, d));
  }
  
  ll dis[V]; memset(dis, -1, sizeof(dis));
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push(make_pair(0, r));
  dis[r] = 0;
  vector<bool> checked(V, false);
  while(!pq.empty()) {
    auto p = pq.top(); pq.pop();
    ll a = p.second, b = p.first;
    if (checked[a] == true) continue;
    checked[a] = true;
    dis[a] = b;
    
    for (auto v : map[a]) {
      pq.push(make_pair((b + v.second), v.first));
//      dis[v.first] = b + v.second;
    }
  }
  
  rep(i, V) {
    if (dis[i] == -1)  cout << "INF" << endl;
    else  cout << dis[i] << endl;
  }
}
