#if 0
なんでTLEするんやぁ…
#endif

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int V, E, R;
vector<pair<int,int>> ST[500010];
int C[100010];
bool Q[100010];
const int Inf = 10000*100000+100;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> V >> E >> R;
  for (int i=0; i<E; ++i) {
    int s, t, d;
    cin >> s >> t >> d;
    ST[s].push_back(make_pair(t,d));
  }
  for (int i = 0; i < V; i++) {
    C[i] = (i == R ? 0 : Inf);
    Q[i] = true;
    P.push(make_pair(C[i], i));
  }
  int cnt = 0;
  while (cnt < V) {
    int d = P.top().first, u = P.top().second; P.pop();
    if (Q[u]) {
      Q[u] = false; cnt++;
      for (auto it = ST[u].begin(); it != ST[u].end(); ++it) {
        int v = (*it).first; int d = (*it).second;
        if (Q[v]) {
          C[v] = min(C[v], C[u] + d);
          P.push(make_pair(C[v], v));
        }
      }
    }
  }
  for (int i = 0; i < V; i++)
    cout << (C[i] == Inf ? "INF" : to_string(C[i])) << endl;
}

