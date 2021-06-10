#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000001;

struct edge{
  int to;
  int cost;
  edge(int to,int cost) : to(to) , cost(cost) {}
};



int main(){
  int V,E,r;
  cin>>V>>E>>r;
  vector< vector< edge > > G(V);
  for(int i=0;i<E;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s].push_back( (edge){t,d} );
  }
  vector<int> d(V,INF);
  d[r]=0;
  typedef pair<int,int> Pair;
  priority_queue< Pair, vector<Pair> , greater<Pair> > Q;
  Q.push( Pair(0,r) );
  while(!Q.empty()){
    Pair p=Q.top();
    Q.pop();
    int pos=p.second;
    int cost=p.first;
    if( cost > d[pos] )continue;
    for(edge e:G[pos]){
      if(cost+e.cost<d[e.to]){
        d[e.to]=cost+e.cost;
        Q.push( Pair(d[e.to],e.to) );
      }
    }
  }
  for(int i=0;i<V;i++){
    if(d[i]==INF)cout<<"INF"<<endl;
    else cout<<d[i]<<endl;
  }
  return 0;
}

