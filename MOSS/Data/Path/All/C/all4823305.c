#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ld = long double; 
int INF = 2*1e9 + 100;


int main(){
  int v,e;cin >> v >> e;
  ll dist[105][105];
  rep(i,105)rep(j,105) {
    if(i!=j) dist[i][j] = 1e18;
    else dist[i][j] = 0;
  }
  rep(i,e){
    int s,t,d;cin >> s >> t >> d;
    dist[s][t] = ll(d);
  }
  // rep(i,v){
  // rep(j,v) {
  //   if(dist[i][j] < 1e18) cout << dist[i][j] <<" ";
  //   else cout << "INF ";
  // }
  // cout << endl;
  // }

  rep(k,v)rep(i,v)rep(j,v){
    if(dist[i][k] == 1e18 || dist[k][j] == 1e18) continue;
    if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
  }
  bool flag = false;
  rep(i,v) if(dist[i][i] < 0) flag = true;
  if(!flag){
    rep(i,v){
      rep(j,v-1) {
        if(dist[i][j] < 1e18) cout << dist[i][j] <<" ";
        else cout << "INF ";
      }
      if(dist[i][v-1] < 1e18) cout << dist[i][v-1];
      else cout << "INF";
      cout << endl;
    }
  }else cout <<"NEGATIVE CYCLE" << endl;

}

