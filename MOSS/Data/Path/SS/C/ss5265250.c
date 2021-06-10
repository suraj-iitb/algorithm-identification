#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define rep2(i,m,n) for(int (i)=(m); (i)<(int)(n); (i)++)
#define all(v) v.begin(),v.end()
const int INF = 1<<30;

int main() {
  int vertex,edge,start;
  cin >>vertex>>edge>>start;
  priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

  vector<vector<pair<int,int> > > dat(vertex,vector<pair<int,int> >(0));
  rep(i,edge) {
    int a, b, c;
    cin >> a >> b >> c;
    dat.at(a).push_back(make_pair(b,c));
  }
  
  pq.push(make_pair(0,start));
  vector<int> output(vertex,INF);//暫定の最短時間を記録
  output.at(start) = 0;
  
  while(!pq.empty()) {
    pair<int,int> state = pq.top();
    pq.pop();
    int st_place = state.second;
    int st_time = state.first;
    
    if(st_time > output.at(st_place)) continue;
    
    for (int i =0; i < dat.at(st_place).size(); i++) {
      pair<int,int> child = dat.at(st_place).at(i);
      if(output.at(child.first) > st_time + child.second) {
        output.at(child.first)  = st_time + child.second;
        pq.push(make_pair(output.at(child.first),child.first));
        //記録更新のときだけpriority_queueにpush ＊ここ重要
      }
    }
  }
  rep(i,vertex) {
    if(output.at(i) == INF) cout << "INF" <<endl;
    else cout << output.at(i)<<endl;
  }
}
  
  
