#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

template <typename T> using pq_asc = priority_queue<T, vector<T>, greater<T>>;

int main(int argc, char const *argv[]) {
  int v, e, r, s, t, d;
  cin >> v >> e >> r;

  vector<vector<pair<int, int>>> g(v);
  const int kUnvisited = -1;
  vector<int> distance(v, kUnvisited);
  pq_asc<pair<int, int>> q; // (d, i)

  for (int i = 0; i < e; i++) {
    cin >> s >> t >> d;
    g[s].push_back(make_pair(d, t));
    // g[t].push_back(make_pair(d, s));
  }

  q.push(make_pair(0, r));
  for (int j = q.top().second; !q.empty(); j = q.top().second) {
    const int cost = q.top().first;
    q.pop();
    if (distance[j] != kUnvisited){
      continue;
    }

    distance[j] = cost;
    for (auto p : g[j]) {
      if (distance[p.second] == kUnvisited) {
        q.push(make_pair(cost + p.first, p.second));
      }
    }
  }

  for (int i = 0; i < v; i++) {
    cout << (distance[i] == kUnvisited ? "INF" : to_string(distance[i]))
         << endl;
  }

  return 0;
}

