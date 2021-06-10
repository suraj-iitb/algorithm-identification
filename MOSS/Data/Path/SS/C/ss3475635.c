#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  vector<int> edges_to;
  vector<int> edges_cost;

  bool done;
  bool in_queue;
  int cost;
  int index;

  bool operator> (const Node& node) const{
    return index > node.index;
  }
  bool operator< (const Node& node) const{
    return index < node.index;
  }

};

using node = struct Node;

int main(){

  node graph[100000];
  node doneNode;
  priority_queue<node> q;

  int v, e, r;
  cin >> v >> e >> r;

  for(int i = 0; i < v; ++i) {
    graph[i].cost = -1;
    graph[i].index = i;
  }

  int s, t, d;
  for(int i = 0; i < e; ++i){
    cin >> s >> t >> d;
    graph[s].edges_to.push_back(t);
    graph[s].edges_cost.push_back(d);
    graph[s].in_queue = false;
  }

  graph[r].cost = 0;
  q.push(graph[r]);
  graph[r].in_queue = true;

  int to, cost;
  while(!q.empty()){
    doneNode = q.top();
    q.pop();

    graph[doneNode.index].done = true;
    graph[doneNode.index].in_queue = false;
    for(int i = 0, n = doneNode.edges_to.size(); i < n; ++i){
      to = doneNode.edges_to[i];
      cost = doneNode.cost + doneNode.edges_cost[i];
      if(graph[to].cost < 0 || cost < graph[to].cost){
        graph[to].cost = cost;
        if(!graph[to].in_queue) q.push(graph[to]);
      }
    }
  }



  for(int i = 0; i < v; ++i){
    if(graph[i].cost < 0) cout << "INF" << endl;
    else cout << graph[i].cost << endl;
  }

  return 0;
}

