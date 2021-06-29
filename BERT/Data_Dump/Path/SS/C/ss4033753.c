#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;

const long MAX_N = 100 * 1000 + 24, INF = 1e9 + 24;

int n, m, s;
int dist[MAX_N];
bool mark[MAX_N];
vector<pii> G[MAX_N];
set<pii> st;

void dfs (int v) {
  mark[v] = true;
  for (auto e : G[v]) {
    if (mark[e.F] == 0) dfs (e.F);
  }
}

int main() {
  memset(mark, 0, sizeof (mark));
  memset(dist, 63, sizeof (dist));
  cin>>n>>m>>s;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    cin>>u>>v>>w;
    G[u].pb(mp(v, w));
    //G[v].pb(mp(u, w));
  }
  //cerr<<"out"<<endl;
  dfs(s);
  st.insert(mp(s, 0));
  dist[s] = 0;
  for (int i = 0; i < n; i++) {
    if (i != s and mark[i]) {
      st.insert(mp(i, INF));
    }
  }
  while (st.size()) {
    pii t = *st.begin();
    st.erase(st.begin());
    for (auto e : G[t.F]) {
      if (dist[e.F] > dist[t.F] + e.S) {
        st.erase(mp(e.F, dist[e.F]));
        dist[e.F] = dist[t.F] + e.S;
        st.insert(mp(e.F, dist[e.F]));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (dist[i] > INF) cout<<"INF"<<endl;
    else cout<<dist[i]<<endl;
  }
}

