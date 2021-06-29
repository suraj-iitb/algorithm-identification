#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>   
#include<limits.h>
using namespace std;
#define i64  long long
#define lint long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


vector<lint> dijkstra(WeightedGraph<lint> &G,lint s)
{ 
  
  vector<lint> path(G.size(),I64_MAX);
  path[s] = 0;
  priority_queue <pair<lint,int> ,vector<pair<lint,int> > ,greater<pair<lint,int> > > que;

  que.emplace(path[s],s);

  while(!que.empty())
  {
    lint cost;
    int idx;
    tie(cost,idx) = que.top();
    que.pop();

    if(path[idx] < cost) continue;
    for (auto &e: G[idx])
    {
      lint next_cost = cost + e.cost;
      if(path[e.to] <= next_cost) continue;
      path[e.to] = next_cost;
      que.emplace(path[e.to],e.to);
    }
  }

  return path;
}
void solve()
{
  int V,E,r;
  cin>>V>>E>>r;
  WeightedGraph<lint> G(V);

  for (int i = 0; i < E; i++)
  {
    lint s,t,d;
    cin>>s>>t>>d;
    edge<lint> edge_v(s,t,d);
    G[s].push_back(edge_v);
  }

  vector<lint> path = dijkstra(G,r);

  for (int i = 0; i < V; i++)
  {
    if(path[i] != I64_MAX)
    cout<<path[i]<<endl;
    else
    cout<<"INF"<<endl;
    
  }
  
  

  return;
}

int main(int argc, const char *argv[])
{

  solve();

  return 0;
}

