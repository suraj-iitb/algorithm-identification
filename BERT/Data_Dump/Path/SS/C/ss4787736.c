#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
#define INF 1<<30
using namespace std;

ll V,E,r;

main() {
  cin >> V >> E >> r;
  vector<P> a[V];
  for (int i =0; i<E; i++) {
    ll b,c,d; cin >> b >> c >> d;
    a[b].push_back(make_pair(c,d));
  }
  
  priority_queue<P, vector<P>, greater<P> > q;
  ll d[V];
  for (int i =0; i<V; i++) d[i] = INF;
  q.push(make_pair(0,r));
  d[r] = 0;
  while (!q.empty()) {
    ll e,f; 
    e = q.top().first; f = q.top().second; q.pop();
    if (d[f] < e) continue;
    for (int i =0; i<a[f].size(); i++) {
      P end = a[f][i];
      if (d[end.first] > d[f] + end.second) {
        d[end.first] = d[f] + end.second;
        q.push(make_pair(d[end.first],end.first));
      }
    }
  }
  for (int i =0; i<V; i++) {
    if (d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}
