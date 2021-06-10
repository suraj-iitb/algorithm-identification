#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

const int INF = 1e9;
struct edge { int to, cost; };
struct node {
  int id, distance;
  node(int id, int distance) {
    this->id = id;
    this->distance = distance;
  }
  bool operator <(const node &theOther) const { return distance < theOther.distance; }
  bool operator >(const node &theOther) const { return distance > theOther.distance; }
};

vector<int> dijkstra(vector<vector<edge> > G, int source) {
  int V = G.size();
  vector<int> distance(V, INF);
  priority_queue<node, vector<node>, greater<node> > que;
  distance[source] = 0;
  que.push(node(source, 0));

  while(!que.empty()) {
    node n = que.top(); que.pop();
    if(distance[n.id] < n.distance) continue;
    for(int i = 0; i < G[n.id].size(); i++) {
      edge e = G[n.id][i];
      if (distance[e.to] > distance[n.id] + e.cost) {
        distance[e.to] = distance[n.id] + e.cost;
        que.push(node(e.to, distance[e.to]));
      }
    }
  }
  return distance;
}

int main () {
  int V, E, r;
  cin >> V >> E >> r;
  vector<vector<edge> > G(V);
  REP(i,E) {
    int s;
    edge e;
    cin >> s >> e.to >> e.cost;
    G[s].push_back(e);
  }
  vector<int> d = dijkstra(G, r);

  REP(i,V){
    if(d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }
  return 0;
}
