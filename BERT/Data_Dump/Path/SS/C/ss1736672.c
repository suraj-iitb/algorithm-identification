#include <bits/stdc++.h>
#define SIZE 300005
#define MOD 1000000007LL
#define EPS 1e-10
#define INF 1 << 30
#define LLINF 1LL << 60
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
typedef pair<int, int> Pii;
typedef pair<double, double> Pdd;
typedef complex<double> dcomplex;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cerr<<a[i]<<((i==a.size()-1)?"\n":" ");}}
ll gcd(ll a,ll b){int c=max(a,b);int d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}
ll fact(ll a){ll b=1;FOR(i,1,a)b*=i;return b;}
ll power(ll x,ll n){ll a=1;REP(i,n)a*=x;return a;}

template<typename T> struct Edge
{
  int src, dst; T w;
  Edge() {};
  Edge(int src, int dst): src(src), dst(dst) {w=1;}
  Edge(int src, int dst, T w): src(src), dst(dst), w(w){}
  bool operator<(const Edge &e)const{return w != e.w ? w > e.w : dst < e.dst;}
  bool operator==(const Edge &e){return dst == e.dst;}
};

template<typename T> class Graph : public vector<vector<Edge<T>>>
{
private:
  pair<T,int> visit(int p, int v)
  {
    pair<T,int> r(0,v);
    for(auto e : (*this)[v]) if(e.dst != p)
    {
      auto t = visit(v,e.dst);
      t.first += e.w;
      if(t.first > r.first) r=t;
    }
    return r;
  }
public:
  Graph(int n){(*this).resize(n);}
  void direct(int s, int t){(*this)[s].push_back(Edge<T>(s,t));}
  void direct(int s, int t, T w){(*this)[s].push_back(Edge<T>(s,t,w));}
  void undirect(int s, int t){direct(s,t);direct(t,s);}
  void undirect(int s, int t, T w){direct(s,t,w);direct(t,s,w);}
  /*
    O(n)
  */
  T diameter(void)
  {
    auto r = visit(-1,0);
    auto t = visit(-1,r.second);
    return t.first;
  }

  /*
    s : start point
    O((n+m)log(n))
  */
  vector<T> dijkstra(int s)
  {
    int n = (*this).size();
    priority_queue<Edge<T>> PQ;
    vector<T> dist(n,INF);
    dist[s] = 0; Edge<T> e(-1,s,0);
    PQ.push(e);
    while(!PQ.empty())
    {
      auto f = PQ.top(); PQ.pop();
      int u = f.dst;
      if(dist[u] < f.w * (-1)) continue;
      REP(j,(*this)[u].size())
      {
        int v = (*this)[u][j].dst;
        if(dist[v] > dist[u] + (*this)[u][j].w)
        {
          dist[v] = dist[u] + (*this)[u][j].w;
          Edge<T> e(-1,v,dist[v]*(-1));
          PQ.push(e);
        }
      }
    }
    return dist;
  }

  vector<T> bellmanFord(int s)
  {
    int n = (*this).size();
    vector<T> dist(n,INF);
    dist[s] = 0;
    REP(i,n)
    {
      bool update = false;
      REP(v,n) for(auto e : (*this)[v])
      {
        if (dist[v] != INF && dist[e.dst] > dist[v] + e.w)
        {
          dist[e.dst] = dist[v] + e.w;
          update = true;
        }
      }
      if(!update) break;
    }
    return dist;
  }
};

int main()
{
  int v,e,r; cin >>v>>e>>r;
  Graph<ll> g(v);
  REP(i,e)
  {
    int s,t,w; cin>>s>>t>>w;
    g.direct(s,t,w);
  }
  auto ans = g.bellmanFord(r);
  for(auto x : ans)
  {
    if(x==INF) cout << "INF" << endl;
    else cout << x << endl;
  }
  return 0;
}
