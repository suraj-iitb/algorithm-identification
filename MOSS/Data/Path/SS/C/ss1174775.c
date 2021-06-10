#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T1, class T2> inline void minup(T1& m, T2 x){ if(m>x) m=static_cast<T2>(x); }
template<class T1, class T2> inline void maxup(T1& m, T2 x){ if(m<x) m=static_cast<T2>(x); }

#define INF 1000000000LL
#define MOD 1000000009
#define EPS 1E-9

typedef ll Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) : src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void Dijkstra(const Graph &g, int s, vector<Weight> &dist, vi &prev)
{
  int n = g.size();
  dist.assign(n, INF); dist[s] = 0;
  prev.assign(n, -1);
  priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
  for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
    Edge e = Q.top(); Q.pop();
    if(prev[e.dst] != -1) continue;
    prev[e.dst] = e.src;
    vrep(f, g[e.dst]) {
      if (dist[f->dst] > e.weight+f->weight) {
        dist[f->dst] = e.weight+f->weight;
        Q.push(Edge(f->src, f->dst, e.weight+f->weight));
      }
    }
  }
}

int V, E, r;
int s, t;
Weight d;

int main()
{
  cin >> V >> E >> r;
  Graph g(V);
  vi prev(V);
  vector<Weight> dist;
  rep(i, E){
    cin >> s >> t >> d;
    g[s].pb(Edge(s, t, d));
  }

  Dijkstra(g, r, dist, prev);

  rep(i, V) if(dist[i] >= INF) puts("INF"); else printf("%d\n", dist[i]);

  return 0;
}
