#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
typedef long long ll;
using namespace std;
typedef pair<int,int> p;

#define MAX 2000000000

struct Edge{
  int to;
  int cost;
};

ll kyori[100001];
vector<Edge> edges[100001];
int Dijkstra(){

}

int main(){
  int V,E,r;

  priority_queue<p,vector<p>,greater<p> > pq;


  cin >> V >> E >> r;

  for(int i=0;i<E;i++){
    int s,t,d;
    cin >> s >> t >> d;
    edges[s].push_back(Edge{t,d});
  }

  for(int i=0;i<V;i++){
    kyori[i] = MAX;
  }
  kyori[r]=0;
  pq.push(p(0,r));

  while(!pq.empty()){
    r = pq.top().second;
    if(kyori[r]>=pq.top().first){
      //kyori[r]=pq.top().first;
      pq.pop();
    }else{
      pq.pop();
      continue;
    }
    for(int i=0;i<edges[r].size();i++){
      if(kyori[edges[r][i].to]>kyori[r]+edges[r][i].cost){
        kyori[edges[r][i].to] = kyori[r]+edges[r][i].cost;
        pq.push(p(kyori[r]+edges[r][i].cost,edges[r][i].to));
      }
    }
  }

  for(int i=0;i<V;i++){
    if(kyori[i] < MAX){
      cout << kyori[i] << endl;
    }else{
      cout << "INF" << endl;
    }
  }

  return 0;
}

