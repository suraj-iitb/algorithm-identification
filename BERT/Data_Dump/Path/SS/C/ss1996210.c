#define NDEBUG

#include <cstdio>

#include <vector>
#include <queue>
#include <cstdint>
#include <cassert>
#include <tuple>

template<typename t> t inf() { assert(0); return t(); }
template<> double inf() { return (1LL << 50); }
template<> long inf() { return (1LL << 50); }
template<> int inf() { return (1LL << 31)-1; }

namespace Graph {
  template<typename tEdge>
  struct Graph {
    Graph() : v(0) {}
    std::vector<tEdge> edges;
    uint32_t v;
  };
  template<typename tEdge>
  void addEdge(Graph<tEdge>& graph, tEdge edge) {
    assert( edge.from < graph.v );
    assert( edge.to   < graph.v );
    graph.edges.push_back(edge);
  }
  template<typename tEdge>
  void setV(Graph<tEdge>& graph, uint32_t v) {
    graph.v = v;
  }
};

namespace Graph {
  namespace Dijkstra {
    template<typename tEdge>
    struct DijkstraInfo {
      std::vector<typename tEdge::wType> dists;
    };
    template<typename tEdge>
    static DijkstraInfo<tEdge> dijkstra(const Graph<tEdge>& graph, uint32_t start) {
      std::vector< std::pair<uint32_t, typename tEdge::wType> > *adj = new std::vector< std::pair<uint32_t, typename tEdge::wType> >[graph.v];
      int n = graph.edges.size();
      for(uint32_t i = 0; i < graph.v; ++i) adj[i].reserve(16);
      for(int i = 0; i < n; ++i) {
        adj[graph.edges[i].from].push_back(std::make_pair(graph.edges[i].to, graph.edges[i].w));
      }
      DijkstraInfo<tEdge> info;
      info.dists.resize(graph.v);
      for(auto &x : info.dists) x = inf<typename tEdge::wType>();
      info.dists[start] = 0;
      std::priority_queue< std::pair<typename tEdge::wType, uint32_t> > q;
      q.push(std::make_pair(0, start));
      while( not q.empty() ) {
        typename tEdge::wType w;
        uint32_t id;
        std::tie(w, id) = q.top(); q.pop(); w = -w;
        for(auto I : adj[id]) {
          uint32_t next;
          typename tEdge::wType nw;
          std::tie(next, nw) = I; nw += w;
          if( info.dists[next] <= nw ) continue;
          info.dists[next] = nw;
          q.push(std::make_pair(-nw, next));
        }
      }
      delete [] adj;
      return info;
    }
  };
};


struct Edge {
  uint32_t from;
  uint32_t to;
  typedef int wType;
  wType w;
};

int main() {
  Graph::Graph<Edge> graph;
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);
  setV(graph, v);
  for(int i = 0; i < e; ++i) {
    Edge edge;
    scanf("%u %u %d", &edge.from, &edge.to, &edge.w);
    addEdge(graph, edge);
  }
  auto res = Graph::Dijkstra::dijkstra(graph, r);
  int n = res.dists.size();
  for(int i = 0; i < n; ++i) {
    printf("%s\n", res.dists[i] == inf<int>() ? "INF" : std::to_string(res.dists[i]).c_str());
  }
  
  return 0;
}
