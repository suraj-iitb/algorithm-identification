#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define INF 1e9
using vi = vector<int>;

int main(int argc, char* argv[]){
  int v,e,r;
  cin >> v >> e >> r;
  vector< vector< pair<int, int> > > edge(v, vector< pair<int, int> >());
  for(int i = 0; i < e; i++){
    int a,b,c;
    cin >> a >> b >> c;
    edge[a].push_back({c, b});
  }
  vi d(v, INF);
  priority_queue<pair<int,int>, vector<pair<int,int>> , greater< pair<int,int> > > q;
  q.push({0, r});
  d[r] = 0;

  while(!q.empty()){
    pair<int, int> now = q.top(); q.pop();
    if(d[now.second] < now.first) continue;
    for(auto next:edge[now.second]){
      if(d[next.second] > d[now.second] + next.first){
        d[next.second] = d[now.second] + next.first;
        q.push({d[next.second], next.second});
      }
    }
  }
  for(int i = 0; i < v; i++){
    if(d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}

