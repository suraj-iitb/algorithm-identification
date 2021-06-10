#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>
#define REP(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;
using pii=pair<int,int>;



vector<int> Dijkstra(vector<vector<pii>> adj_list,int start){
  int n=adj_list.size();
  /*初期化*/
  vector<int> distance(n,INF);
  vector<int> pre(n);
  distance.at(start)=0;
  priority_queue<pii,vector<pii>,greater<pii>> unsettled;/*未確定の頂点*/
  REP(u,n){
    unsettled.push(make_pair(distance.at(u),u));
  }

  /*本計算*/
  while(!unsettled.empty()){
    int u;
    tie(ignore,u)=unsettled.top();
    unsettled.pop();/*uを確定*/
    /*uから伸びている辺の先へ書き込み*/

    for(auto vpair : adj_list.at(u)){
      int weight_u_to_v,v;
      tie(v,weight_u_to_v)=vpair;
      int alt=distance.at(u)+weight_u_to_v;
      /*更新*/
      if(distance.at(v)>alt){
        distance.at(v)=alt;
        pre.at(v)=u;
        unsettled.push(make_pair(alt,v));

      }
    }

  }
  return distance;

}

int main() {
  int V,E,r;
  cin>>V>>E>>r;
  vector<vector<pair<int,int>>> adj_list(V);
  
  REP(i,E){
    int s,t,d;
    cin>>s>>t>>d;
    adj_list.at(s).push_back(make_pair(t,d));

  }

  vector<int> distance=Dijkstra(adj_list,r);
  REP(i,V){
    if(distance.at(i)==INF){
      cout<<"INF"<<endl;
    }else{
      cout<<distance.at(i)<<endl;
    }
  }


  return 0;
}
