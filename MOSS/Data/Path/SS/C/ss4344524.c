#include "bits/stdc++.h"
using namespace std;
using ll=long long;

const ll INF=1LL<<60;

#include <vector>
#include <numeric>
#include <queue>
#include <functional>

template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int,T>>> &g,int s){
   //const T INF=std::numeric_limits<T>::max();
   using P=pair<T,int>;
   std::vector<T> dist(g.size(),INF);
   dist[s]=0;
   std::priority_queue<P,std::vector<P>,std::greater<P>> pq;
   pq.emplace(0,s);
   while(!pq.empty()){
      int idx;
      T cost;
      tie(cost,idx)=pq.top();
      pq.pop();
      if(cost>dist[idx]) continue;
      for(auto &e:g[idx]){
         T next_cost=cost+e.second;
         if(next_cost>=dist[e.first]) continue;
         dist[e.first]=next_cost;
         pq.emplace(next_cost,e.first);
      }
   }
   return dist;
}

int main(){
   int V,E,r;
   cin>>V>>E>>r;
   using P=pair<int,ll>;
   vector<vector<P>> g(V);
   for(int i=0;i<E;++i){
      int s,t;
      cin>>s>>t;
      ll d;
      cin>>d;
      g[s].emplace_back(t,d);
   }

   auto d=dijkstra(g,r);
   for(int i=0;i<V;++i){
      if(d[i]==INF) cout<<"INF"<<endl;
      else cout<<d[i]<<endl;
   }
}
