#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll v,e,r;
  cin >> v >> e >> r;
  vector<map<ll,ll>> E(v);
  for(ll i=0;i<e;i++) {
    ll s,t,d;
    cin >> s >> t >> d;
    E[s][t]=d;
  }
  priority_queue<pll,vector<pll>,greater<pll>> q;
  vector<ll> d(v,-1);
  d[r]=0;
  for(auto p:E[r]) {
    q.push(pll(p.second,p.first));
  }
  while(q.size()) {
    auto p=q.top();
    q.pop();
    ll f=p.second;
    if(d[f]>-1) continue;
    d[f]=p.first;
    for(auto t:E[f]) {
      q.push(pll(d[f]+t.second,t.first));
    }
  }
  for(ll i=0;i<v;i++) {
    if(d[i]<0) {
      cout << "INF" << endl;
    }
    else {
      cout << d[i] << endl;
    }
  }
}
