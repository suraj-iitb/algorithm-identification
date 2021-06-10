#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> P;

const static int VSIZE = 100000 + 10;
const static int INF = 1 << 30;

std::vector<P> G[VSIZE];
int W[VSIZE];
bool T[VSIZE];

int main()
{
  std::priority_queue<P> q;
  int n, m, r;

  std::cin >> n >> m >> r;
  for (int i = 0; i < m; ++i)
  {
    int s, t, d;
    std::cin >> s >> t >> d;
    G[s].push_back(P(t, d));
  }

  for (int i = 0; i < n; ++i)
  {
    W[i] = INF;
  }

  W[r] = 0;
  q.push(P(0, r));

  while (!q.empty())
  {
    P data = q.top(); q.pop();
    int u = data.second;

    if (W[u] < data.first * (-1)) continue;

    T[u] = true;

    for (int i = 0; i < G[u].size(); ++i)
    {
      int v = G[u][i].first;
      if (T[v]) continue;

      int ucost = W[u] + G[u][i].second;
      if (W[v] > ucost)
      {
        W[v] = ucost;
        q.push(P(-ucost, v));
      }
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (W[i] == INF)
    {
      std::cout << "INF" << std::endl;
    }
    else
    {
      std::cout << W[i] << std::endl;
    }
    
  }
  return 0;
}

