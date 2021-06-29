#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
const int INF = 0x7fffffff;

int gcd(int x,int y){
  int mi,ma;
  ma = max(x,y);
  mi = min(x,y);
  if(ma % mi == 0){
    return mi;
  }
  else{
    return gcd(mi,ma % mi);
  }
}
struct Edge{
  int to;
  int weight;

  Edge(int to,int weight){
    this->to = to;
    this->weight = weight;
  }
};

using Graph = vector<vector<Edge>>;

int main(){
  long ii,jj,kk;
  vector<int> a;

  int e,v,s;
  cin >> e >> v >> s;
  const int INF = 10000 * 100000 + 1;
  Graph g(e);
  vector<int> cost(e);
  queue<int> next;
  int from,to,weight;

  for(ii=0;ii<e;ii++){
    cost[ii] = INF;
  }
  cost[s] = 0;
  
  for(ii=0;ii<v;ii++){

    cin >> from >> to >> weight;
    g[from].push_back(Edge(to,weight));
    g[to].push_back(Edge(to,weight));
    
  }

  next.push(s);
  int n;

  while(!next.empty()){
    n = next.front();
    next.pop();


    int from,to,weight;
    from = n;
    
    for(Edge ed : g[n]){
      weight = ed.weight;
      to = ed.to;

      //if(cost[to] == INF){
      //
      //}
      
      if(cost[from] + weight < cost[to]){
	cost[to] = cost[from] + weight;
	next.push(to);
      }
    }
    
  }

  for(ii=0;ii<e;ii++){
    if(cost[ii] != INF){
      cout << cost[ii] << endl;
    }
    else{
      cout << "INF" << endl;
    }
  }
  return 0;
}

