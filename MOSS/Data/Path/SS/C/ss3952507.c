#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
typedef long long ll;
using namespace std;

struct Dijkstra{
  int n,i;
  vector<vector<pair<int,int> > > edge; //cost,to
  vector<int> distance;
  vector<int> prev;

  void init(int v){
    n=v;
    edge.resize(n);
    distance.resize(n);
    prev.resize(n);
  }

  void input(int from,int to,int cost){
    edge[from].push_back({cost,to});
  }

  void calc(int start){
    for(i=0;i<n;i++){
      distance[i]=1e9+7;
      prev[i]=-1;
    }
    distance[start]=0;

    priority_queue<pair<int,int> > q; //distance,n
    pair<int,int> node;
    int from,to,tmp;
    q.push({0,start});

    while(!q.empty()){
      node=q.top();
      from=node.second;
      q.pop();
      if(node.first>distance[node.second]){
        continue;
      }

      for(i=0;i<edge[from].size();i++){
        to=edge[from][i].second;
        tmp=distance[from]+edge[from][i].first;
        if(distance[to]>tmp){
          distance[to]=tmp;
          prev[to]=from;
          q.push({tmp*-1,to}); //greater
        }
      }
    }
  }
};

int main(void){
  int v,e,r,s,t,d,i,j;
  Dijkstra graph;

  cin>>v>>e>>r;
  graph.init(v);
  for(i=0;i<e;i++){
    cin>>s>>t>>d;
    graph.input(s,t,d);
  }
  graph.calc(r);

  for(i=0;i<v;i++){
    if(graph.distance[i]!=1e9+7)cout<<graph.distance[i]<<endl;
    else cout<<"INF"<<endl;
  }

  return 0;
}

