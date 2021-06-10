#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

const int INF = 1e9;

int main()
{
  int n, m, s;
  cin >> n >> m >> s;
  
  vector<vector<P>> e(n, vector<P>(0));
  rep(i, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    e[a].emplace_back(P(b, c));
  }
  
  vector<int> d(n, INF);
  queue<int> q;
  int cnt = 0;
  
  q.push(s);
  d[s] = 0;
  while(q.size())
  {
    int a = q.front();
    q.pop();
    
    for(auto x : e[a])
    {
      int nd = d[a] + x.second;
      if(nd < d[x.first])
      {
        q.push(x.first);
        d[x.first] = nd;
      }
    }
  }
  
  rep(i, n)
  {
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }

  return 0;
}
