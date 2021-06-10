#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll inf=1e18;

int main() {
  ll v,e;
  cin >> v >> e;
  vector<vector<ll>> d(v,vector<ll>(v,inf));
  for(ll i=0;i<v;i++) {
    d[i][i]=0;
  }
  for(ll i=0;i<e;i++) {
    ll s,t,dis;
    cin >> s >> t >> dis;
    d[s][t]=dis;
  }
  for(ll k=0;k<v;k++) {
    for(ll f=0;f<v;f++) {
      for(ll t=0;t<v;t++) {
        if(d[f][k]!=inf&&d[k][t]!=inf) {
          d[f][t]=min(d[f][t],d[f][k]+d[k][t]);
        }
      }
    }
  }
  for(ll f=0;f<v;f++) {
    if(d[f][f]<0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for(ll f=0;f<v;f++) {
    for(ll t=0;t<v;t++) {
      if(t!=0) {
        cout << " ";
      }
      if(d[f][t]==inf) {
        cout << "INF";
      }
      else {
        cout << d[f][t];
      }
    }
    cout << endl;
  }
}
