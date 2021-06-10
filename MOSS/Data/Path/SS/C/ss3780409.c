#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
const int INF = pow(10, 8);
const ll LINF = ll(1e18);
struct edge{
  int to;
  int cost;
};
int main(){
  int v, e, r;cin>>v>>e>>r;
  vector<vector<edge> > graph(v, vector<edge>());
  vector<ll> dis(v, LINF);
  dis[r]=(ll)0;
  for(int i=0;i<e;i++){
    int s, t, d;cin>>s>>t>>d;
    edge ed = {t, d};
    graph[s].push_back(ed);
  }
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P((ll)0, r));
  while(que.size()){
    P p = que.top();que.pop();
    int x = p.second;
    if(dis[x] < p.first)continue;
    for(edge& ed:graph[x]){
      if(dis[ed.to] > dis[x]+(ll)ed.cost){
        dis[ed.to] = dis[x]+(ll)ed.cost;
        que.push(P(dis[ed.to], ed.to));
      }
    }
  }
  for(int i=0;i<v;i++){
    if(dis[i]==LINF)cout<<"INF"<<endl;
    else cout<<dis[i]<<endl;
  }
  return 0;
}

