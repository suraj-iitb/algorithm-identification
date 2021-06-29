#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 60);
const bool WHITE = false;
const bool BLACK = true;

int main()
{
  int N, M, r;
  cin >> N >> M >> r;
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; i++)
  {
    int s, t, d;
    cin >> s >> t >> d;
    adj.at(s).push_back(make_pair(t, d));
  }
  vector<long long> d(N, INF);
  vector<bool> color(N, WHITE);
  priority_queue<pair<long long, int>> pq;
  pq.push(make_pair(0, r));
  while (!pq.empty())
  {
    long long cost;
    int u;
    tie(cost, u) = pq.top();
    cost *= -1;
    pq.pop();
    if (color.at(u) == BLACK)
    {
      continue;
    }
    color.at(u) = BLACK;
    d.at(u) = cost;
    for (int i = 0; i < adj.at(u).size(); i++)
    {
      int v, cost_uv;
      tie(v, cost_uv) = adj.at(u).at(i);
      if (color.at(v) == WHITE && d.at(v) > d.at(u) + cost_uv)
      {
        pq.push(make_pair(-1 * (d.at(u) + cost_uv), v));
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (d.at(i) < INF)
    {
      cout << d.at(i) << endl;
    }
    else
    {
      cout << "INF" << endl;
    }
  }
}
