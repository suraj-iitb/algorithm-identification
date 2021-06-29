#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template< typename T >
struct RadixHeap
{
  using uint = unsigned;
  vector< pair< uint, T > > v[33];
  uint size, last;

  RadixHeap() : size(0), last(0) {}

  bool empty() const { return size == 0; }

  inline int getbit(int a)
  {
    return a ? 32 - __builtin_clz(a) : 0;
  }

  void push(uint key, const T &value)
  {
    ++size;
    v[getbit(key ^ last)].emplace_back(key, value);
  }

  pair< uint, T > pop()
  {
    if(v[0].empty()) {
      int idx = 1;
      while(v[idx].empty()) ++idx;
      last = min_element(begin(v[idx]), end(v[idx]))->first;
      for(auto &p : v[idx]) v[getbit(p.first ^ last)].emplace_back(p);
      v[idx].clear();
    }
    --size;
    auto ret = v[0].back();
    v[0].pop_back();
    return ret;
  }
};


template <typename T>
vector<T> dijkstra(int s,vector<vector<pair<int, T> > > & G,T INF){
  int n=G.size();
  vector<T> d(n,INF);
  vector<int> b(n,-1);
  RadixHeap<T> q;
  d[s]=0;
  q.push(d[s],s);
  while(!q.empty()){
    auto p=q.pop();
    int v=p.second;
    if(d[v]<(T)p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      T c=e.second;
      if(d[u]>d[v]+c){
        d[u]=d[v]+c;
        b[u]=v;
        q.push(d[u],u);
      }
    }
  }
  return d;
}

//INSERT ABOVE HERE
signed main(){
  int n,m,r;
  scanf("%d %d %d",&n,&m,&r);
  using P = pair<int, int>;
  vector<vector<P > > G(n);
  for(int i=0;i<m;i++){
    int s,t,d;
    scanf("%d %d %d",&s,&t,&d);
    G[s].emplace_back(t,d);
  }
  auto ans=dijkstra(r,G,INT_MAX);
  for(int i=0;i<n;i++){
    if(ans[i]==INT_MAX) puts("INF");
    else printf("%d\n",ans[i]);
  }
  return 0;
}

