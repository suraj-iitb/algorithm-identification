#include <bits/stdc++.h>

template<typename TWeight>
class Dijkstra {
public:
  std::vector< std::tuple<int, TWeight> > *edges;
  int v;
  TWeight inf;
};

template<typename TWeight>
Dijkstra<TWeight> initDijkstra(int v, TWeight inf) {
  Dijkstra<TWeight> res;
  res.edges = new std::vector< std::tuple<int, TWeight> > [v + 3];
  res.v     = v + 3;
  res.inf   = inf;
  return res;
}

template<typename TWeight>
void addEdge(Dijkstra<TWeight>& x, int from, int to, TWeight w) {
  x.edges[from].push_back(std::make_tuple(to, w));
}

template<typename TWeight>
std::vector<TWeight> eval(Dijkstra<TWeight> x, int source) {
  std::vector<TWeight> res(x.v, x.inf);
  res[source] = 0;
  std::priority_queue< std::tuple<TWeight, int> > q;
  q.push(std::make_tuple(0, source));
  while( not q.empty() ) {
    TWeight base; int id;
    std::tie(base, id) = q.top(); q.pop();
    base = -base;
    for(std::tuple<int, TWeight> edge : x.edges[id]) {
      int next; TWeight dist;
      std::tie(next, dist) = edge;
      auto newdist = base + dist;
      if( newdist >= res[next] ) continue;
      res[next] = newdist;
      q.push(std::make_tuple(-newdist, next));
    }
  }
  return res;
}

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);
  auto graph = initDijkstra<long>(v, (1LL << 55));
  for(int i = 0; i < e; ++i) {
    int s, t; long d;
    scanf("%d %d %ld", &s, &t, &d);
    addEdge(graph, s, t, d);
  }
  auto dists = eval(graph, r);
  for(int i = 0; i < v; ++i) {
    if( dists[i] != graph.inf ) {
      printf("%ld\n", dists[i]);
    }
    else {
      puts("INF");
    }
  }
}
