#include<iostream>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>

#define MAX_V 100001
#define INF (1e9 + 1)


typedef long long ll;
#define REP(i,n) for(long long int (i)=0;(i) < (n);(i)++)
using namespace std;

struct edge{
  int to,dist;
};

int V,E,r,a,b,c;

vector<edge> G[MAX_V];

int d[MAX_V];

void dijkstra(){
  int i;
  REP(i,MAX_V) d[i] = INF;
  d[r]=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
  Q.push(make_pair(0,r));
  while(!Q.empty()){
    pair<int,int> p = Q.top();

    Q.pop();
    int pos = p.second,cost = p.first;
    REP(i,G[pos].size()){
      edge e = G[pos][i];
      int to = e.to;
      int newcost = cost + e.dist;
      if(newcost < d[to]){
        d[to] = newcost;
        Q.push(make_pair(d[to],to));
      }
    }
  }

    REP(i,V){
      if(d[i]==INF)printf("INF\n");
      else printf("%d\n",d[i]);
    }
}

int main(){
    int i;
    scanf("%d %d %d",&V,&E,&r);
    REP(i,E){
      scanf("%d %d %d",&a,&b,&c);
      G[a].push_back((edge){b,c});
    }
    dijkstra();
    return 0;

}

