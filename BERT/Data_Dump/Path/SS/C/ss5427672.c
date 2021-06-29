#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, n) for (int i = (int)(l); i < (int)(n); i++)
#define drep(i, n) for (int i = (int)(n); i > 0; i--)
#define INF (pow(10,12))
#define def (200007)
#define MOD (1000000007)
typedef vector<int> veci;
typedef vector<vector<int>> Veci;
typedef vector<int64_t> vecit;
typedef vector<vector<int64_t>> Vecit;
typedef int64_t intt;
typedef vector<vector<double>> Vecd;
typedef vector<double> vecd;
typedef pair<int, int> P;
/*veci のときdist.resize(N) Veciのとき2回resize;
dp.assign(N,-1);*/

struct edge{
  int to;
  int cost;
};

int main(){
  int V,E,r;cin>>V>>E>>r;
  vector<vector<P>> gragh(V);
  rep(i,0,E){
    int s,t,d;cin>>s>>t>>d;
    gragh[s].push_back({d,t});
  }
  priority_queue<P, vector<P>, greater<P>> que;
  vecit costs(V,INF);
  veci pre(V,0);
  pre[0]=-1;
  costs[r]=0;
  que.push({0,r});
  /*rep(i,0,V){
    rep(j,0,gragh[i].size()){
      cout<<"{"<<gragh[i][j].first<<","<<gragh[i][j].second<<"}";
    }cout<<endl;
  }*/
  while(!que.empty()){
    P pai=que.top();
    que.pop();
       //{cost,to}
    for(P u : gragh[pai.second]){
      if(costs[u.second] > costs[pai.second]+u.first){
      	costs[u.second] = costs[pai.second]+u.first;
        que.push({costs[u.second],u.second});
        pre[u.second]=pai.second;
      }
    }
  }
  rep(i,0,V){
    if(costs[i]==INF)cout<<"INF"<<endl;
    else cout<<costs[i]<<endl;
  }
  
  
      
  return 0;
}
