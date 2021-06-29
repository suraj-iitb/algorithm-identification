#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int main(){
  int nv,ne,r,s,t,d,d0;
  cin >> nv >> ne >> r;
  vector<vector<pair<int,long long>>> G(nv);
  for(int i=0;i<ne;i++){
    cin >> s >> t >> d;
    G[s].push_back(make_pair(t,d));
  }
  vector<long long> dist(nv,-1);
  dist[r]=0;
  priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>> que;
  que.push(make_pair(dist[r],r));
  while(que.size()){
    tie(d0,s)=que.top();
    que.pop();
    if(d0>dist[s]) continue;
    for(auto e:G[s]){
      tie(t,d)=e;
      if(dist[t]==-1||dist[t]>dist[s]+d){
        dist[t]=dist[s]+d;
        que.push(make_pair(dist[t],t));
      }
    }
  }
  for(int i=0;i<nv;i++){
    if(dist[i]==-1){
      cout << "INF" << endl;
    } else {
      cout << dist[i] << endl;
    }
  }
}
