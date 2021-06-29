#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)

#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
typedef long long ll;
#define P pair<int,int>
#define mk make_pair

int main(){
  int V,E,r;
  cin >> V >> E >> r;
  vector<P> G[V];
  rep(i,E){
    int s,t,d;
    cin >> s >> t >> d;
    G[s].push_back(mk(t,d));
  }

  priority_queue<P, vector<P>, greater<P>> Q;
  ll d[V];
  rep(i,V) d[i] = INF;
  d[r] = 0;
  Q.push(mk(0,r));
  while(!Q.empty()){
    P p = Q.top();
    Q.pop();
    int v = p.second;
    if(d[v]< p.first) continue;
    for(int i=0; i<G[v].size(); i++){
      P ed = G[v][i];
      if(d[ed.first] > d[v]+ed.second){
        d[ed.first] = d[v]+ed.second;
        Q.push(mk(d[ed.first], ed.first));
      }
    }
  }
  rep(i,V){
    if(d[i]==INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
  return 0;
}

