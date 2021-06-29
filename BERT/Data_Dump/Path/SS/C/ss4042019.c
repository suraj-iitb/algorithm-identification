#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0; i<n; i++)
typedef pair<ll,ll> P;



int main()
{
  ll n,m,r;
  cin >> n >> m >> r;

  // weight, end point
  vector<vector<pair<ll,ll>> > G(n);

  for (ll i = 0; i < m; i++)
  {
    ll s,t,d;
    cin >> s >> t >> d;
    G[s].emplace_back(make_pair(d,t));
  }

  vector<ll> dist(n,1e+10);

  priority_queue<P,vector<P>,greater<P> > que;
  dist[r] = 0;
  que.push(make_pair(0,r));
  
  while(!que.empty())
  {
    /*
    cout << "-----------------------" << endl;
    //debugging
    cout << "dist:" << endl;
    for(auto x:dist)
    {
      if(x!=1e+10) cout << x << " ";
      else cout << "INF" << " ";
    }
    cout << endl;
    cout << "que:" << endl;
    priority_queue<P,vector<P>,greater<P> > tmpque = que;
    while(!tmpque.empty())
    {
      P p = tmpque.top();
      cout << p.first << " " << p.second << endl;
      tmpque.pop();
    }
    */

    // main part
    P p = que.top();
    que.pop();
    ll v = p.second;
    if(dist[v] < p.first) continue;

    /*
    cout << "edges: ";
    cout << v << " " << G[v].size() << endl;
    */
    for(auto q:G[v])
    {
      //cout << "from " << v << " to " << q.second;
      if(dist[q.second] > dist[v] + q.first)
      {
        dist[q.second] = dist[v] + q.first;
        que.push(make_pair(dist[q.second],q.second));
        //cout << ": updated" << endl;
      } else {
        //cout << ": skipped" << endl;
      }
    }
  }

  //cout << "-----------------------" << endl;


  for(auto x:dist)
  {
    if(x!=1e+10) cout << x << endl;
    else cout << "INF" << endl;
  }

  return 0;
}
