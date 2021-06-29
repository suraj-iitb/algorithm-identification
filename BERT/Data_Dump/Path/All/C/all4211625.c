/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll v,e,s,t,d,g[105][105]={},f=0;
  cin >> v >> e;
  for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++) {
      if(i!=j) {
        g[i][j]=INF;
      }
    }
  }
  for(int i=0; i<e; i++) {
    cin >> s >> t >> d;
    g[s][t]=d;
  }
  for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++) {
      for(int k=0; k<v; k++) {
        g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
      }
    }
  }
  for(int i=0; i<v; i++) {
    if(g[i][i]<0) {
      f=1;
    }
  }
  if(f) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for(int i=0; i<v; i++) {
    for(int j=0; j<v; j++) {
      if(g[i][j]>INF/2) {
        cout << "INF";
      }
      else {
        cout << g[i][j];
      }
      if(j!=v-1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}
