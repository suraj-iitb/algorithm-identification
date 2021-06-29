#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct E{
  int to;
  T cost;
};

template<typename T>
vector<T>dijkstra(vector<vector<E<T>>>g,int s){
  T inf=numeric_limits<T>::max();
  vector<T>d(g.size(),inf);
  using Type=pair<T,int>;
  using Container=vector<Type>;
  using Cmp=greater<Type>;
  priority_queue<Type,Container,Cmp>q; 
  d[s]=0;
  q.push({d[s],s});
  while(!q.empty()){
    T cost=q.top().first;
    int from=q.top().second;
    q.pop();
    if(d[from]!=cost)continue;
    for(auto e:g[from]){
      T next_cost=e.cost+cost;
      if(d[e.to]>next_cost){
        d[e.to]=next_cost;
        q.push({d[e.to],e.to});
      }
    }
  }
  return d;
}

int main(){
  int N,M,S;
  cin>>N>>M>>S;
  vector<vector<E<int>>>G(N);
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G[a].push_back({b,c});
  }
  auto ans=dijkstra<int>(G,S);
  for(auto it:ans){
    if(it==INT_MAX)cout<<"INF"<<endl;
    else cout<<it<<endl;
  }
  return 0;
}

