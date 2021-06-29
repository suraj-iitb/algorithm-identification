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
const long long INF = 9999999999999;

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
  long long from;
  long long to;
  long long weight;
  Edge(long long from,long long to,long long weight){
    this->from   = from;
    this->to     = to;
    this->weight = weight;
  }
};


using Graph = vector<vector<Edge>>;

bool IsNegativeCycle(vector<Edge>& edges,vector<long long>& cost,int v){
  int ii;
  int from,to,weight;
  for(ii=0;ii<v;ii++){
    for(Edge e : edges){
      //cout << "from:" << e.from << "to:" << e.to << "weight" << e.weight << endl;;
      //cout << "cost[from]" << cost[e.from] << "cost[to]" << cost[e.to] << endl;

      if(cost[e.from] + e.weight < cost[e.to]){
	cost[e.to] = cost[e.from] + e.weight;
	if(ii == (v-1)){
	  return true;
	}
      }
    }
  }
  //cost[1] = 999;
  return false;
}

int main(){
  long ii,jj,kk;
  vector<int> a;

  const long long INF = 9999999999999;

  int e,v,s;

  cin >> v >> e;

  //vector<Edge> edges(e);
  vector<Edge> edges;
  Graph g(v);

  vector<long long> cost(v);
  int from,to,weight;

  for(ii=0;ii<e;ii++){
    cin >> from >> to >> weight;
    
    Edge edge(from,to,weight);
    edges.push_back(edge);
    
    g[from].push_back(edge);
    //g[to].push_back(edge);
  }


  for(ii=0;ii<v;ii++){
    cost[ii] = INF;
  }

  cost[s] = 0;
  
  bool negativeFlg ;
  negativeFlg = IsNegativeCycle(edges,cost,v);

  if(negativeFlg){
    cout << "NEGATIVE CYCLE" << endl;
  }
  else{
    queue<long> q;
    long long cost2[v][v];
    long long from;
    for(ii=0;ii<v;ii++){
      for(jj=0;jj<v;jj++){
	cost2[ii][jj] = INF;
      }
    }

    for(ii=0;ii<v;ii++){
      cost2[ii][ii] = 0;
      q.push(ii);

      while(!q.empty()){
	from = q.front();
	q.pop();

	for(Edge ed : g[from]){
	  if(cost2[ii][from] + ed.weight < cost2[ii][ed.to]){
	    cost2[ii][ed.to] = cost2[ii][from] + ed.weight;
	    q.push(ed.to);
	  }
	}
	
      }
    }
    
    for(ii=0;ii<v;ii++){
      for(jj=0;jj<v;jj++){

	if(cost2[ii][jj] == INF){
	  cout << "INF" ;
	}
	else{
	  cout << cost2[ii][jj] ;
	}
	if(jj != (v-1)){
	  cout << " " ;
	}
      }
      cout << endl;
    }
  }
  return 0;
}

