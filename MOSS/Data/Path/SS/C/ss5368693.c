#include<iostream>
#include<vector>
#include<queue>
#define INFTY 2100000000

using namespace std;
typedef pair<int,int> P;

struct V{
  int nextv,wei;
};
vector<V> g[100000];
int d[100000];
vector<bool> visited;
priority_queue<P,vector<P>, greater<P> > que;
int v,e,r;


void dijkstra(void){

  //init
  for (int i=0; i<v ; i++)
    d[i]=INFTY;
  d[r]=0;

  visited.assign(v,false);
  visited[r]=true;

  que.push(P(0,r));

  while(!que.empty()){

    P p = que.top();
    int newv = p.second;

    que.pop();

    if (d[newv]<p.first)continue;

    for (int i=0; i<g[newv].size(); i++){

      if( d[newv]+g[newv][i].wei < d[g[newv][i].nextv] ){
        d[g[newv][i].nextv] = d[newv]+g[newv][i].wei;
        que.push( P(d[g[newv][i].nextv], g[newv][i].nextv));
      }
    }
  }
}

int main(){

  cin >> v >> e >> r;

  for (int i=0; i<e; i++){
    int a,b,c;
    cin >> a >> b >> c;
    g[a].push_back( (V){b,c});
  }

  dijkstra();

  for (int i=0; i<v ;i++){
    if(d[i]!=INFTY)
      cout << d[i] << endl;
    else
      cout << "INF" << endl;
  }
}

