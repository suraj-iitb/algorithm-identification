#include<bits/stdc++.h>
using namespace std;

struct edge{
  int to;
  int cost;
};

int main(){
  int v,e;cin>>v>>e;
  int r;cin>>r;
  vector<vector<edge>> G(v);
  for (int i = 0; i < e; i++) {
    int s,t,d;cin>>s>>t>>d;
    edge tmp; tmp.to = t;tmp.cost = d;
    G.at(s).push_back(tmp);
  }

  //累積コスト,頂点
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> que;
  que.push(pair<int,int>(0,r));
  vector<int> dist(v,1e9);
  while(!que.empty())
  {
    pair<int,int> p = que.top();
    que.pop();
    int now = p.second;
    int cost = p.first;
    dist.at(now) = min(dist.at(now),cost);
    for (auto && a : G.at(now)) {
      int ncost = a.cost;
      int nver = a.to;
      if(dist.at(nver) != 1e9)continue;
      pair<int,int> pn;
      pn.first = dist.at(now) + ncost;
      pn.second = nver;
      que.push(pn);
    }
    
    /*
    for (auto && a : dist) {
    if(a == 1e9)cout<<"INF";
    else cout << a;
    cout<<endl;
  }
  cout << endl;
  */

  }
  for (auto && a : dist) {
    if(a == 1e9)cout<<"INF";
    else cout << a;
    cout<<endl;
  }
}



