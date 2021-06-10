#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct edge {
  int to,w;
};
#define MAX 1000000005
vector<vector<edge> > g;
//vector<bool> f;
vector<int> min_d;
priority_queue <edge, vector<edge>,greater<edge>> que;
bool operator > (const edge a,const edge b){return a.w>b.w;};

void dfs(int v,int n){
  edge this_p;
  for(int i = 0; i<n; i++)min_d[i] = MAX;
  min_d[v] = 0;
  for(auto e : g[v]){
    que.push(e);
    min_d[e.to] = e.w;
  }
  //f[v]=true;

  while(!que.empty()){
    this_p = que.top();
    que.pop();
    //f[this_p.to] = true;
    for(auto e : g[this_p.to]){
      //if(f[e.to])continue;
      if(min_d[e.to] > min_d[this_p.to]+e.w){
        min_d[e.to] = min_d[this_p.to]+e.w;
        que.push(e);
        //cout<<min_d[i]<<" : "<<min_d[min_node]<<":"<<g[min_node][i]<<endl;
      }
    }
  }
}
int main(){
  int v,e,s,t,r,w;
  edge tmp;
  cin>>v>>e>>r;
  g.resize(v);
  //f.resize(v);
  min_d.resize(v);
  tmp.to=r;
  tmp.w=0;
  g[r].push_back(tmp);
  for(int i=0;i<e;i++){
    cin>>s>>t>>w;
    tmp.to=t;
    tmp.w=w;
    g[s].push_back(tmp);
  }
  dfs(r,v);
  for(auto i : min_d){
    if(i==MAX)cout<<"INF"<<endl;
    else cout<<i<<endl;
  }
  return 0;
}

