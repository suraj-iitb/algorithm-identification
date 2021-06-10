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
template<class T1, class T2> inline bool minup(T1& m, T2 x){ if(m>x){ m=static_cast<T2>(x); return true; } return false; }
template<class T1, class T2> inline bool maxup(T1& m, T2 x){ if(m<x){ m=static_cast<T2>(x); return true; } return false; }

#define INF 100000000000000LL
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

void WarshallFloyd(const Matrix &g, Matrix &dist)
{
  int n = g.size();
  dist = g;
  rep(k, n) rep(i, n) rep(j, n) minup(dist[i][j], dist[i][k] + dist[k][j]);
}

int V, E;
int s, t;
Weight d;

int main()
{
  cin >> V >> E;
  Matrix g(V, Array(V, INF + INF));  rep(i, V) g[i][i] = 0LL;
  Matrix dist(V, Array(V));
  rep(i, E){
    cin >> s >> t >> d;
    g[s][t] = d;
  }

  WarshallFloyd(g, dist);

  rep(i, V) if(dist[i][i] < 0LL){
    puts("NEGATIVE CYCLE");
    return 0;
  }

  rep(i, V) rep(j, V){
    if(dist[i][j] >= INF) printf("INF");
    else cout << dist[i][j];
    putchar(j>=V-1 ? '\n' : ' ');
  }

  return 0;
}
