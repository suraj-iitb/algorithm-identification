#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define F first
#define S second
using namespace std;
typedef pair<int,int>p;
const int INF = 2000000000;

priority_queue<p> p_que;
vector<p> g[100000];
int d[100000];

void pre(int size) {
  for ( int i = 0; i < size; i++) {
    d[i] = INF;
  }
}

main() {
  int v, e, r;
  int s, t, w;
  
  cin >> v >> e >> r;
  pre(v);
  for (int i = 0; i < e; i++) {
    cin >> s >> t >> w;
    g[s].push_back(p(t,w));
  }

  p_que.push(p(r,0));
  d[r] = 0;
  while ( !p_que.empty() ) {
    p now = p_que.top(); p_que.pop();
    int pos = now.F;
    int cost = now.S;
    
    for ( int i = 0; i < g[pos].size() ; i++) {
      int next = g[pos][i].F;
      int ncost = cost + g[pos][i].S;
      if ( d[next] > ncost ) {
	d[next] = ncost;
	p_que.push(p(next,ncost));
      }
    }
    
  }
  
  for ( int i = 0; i < v; i++) {
    if ( d[i] == INF ) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }

  return (0);
}

