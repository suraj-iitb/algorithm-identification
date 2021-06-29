#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const ll MAX = 510000;
const ll MOD = 1000000007;

struct edge {
    ll from;
    ll to;
    ll cost;
};

ll V, E, d[210];
edge es[21000];

bool has_negative_loop(ll s) {
    fill(d, d + V, 1e16);
    d[s] = 0;
    for (ll i = 0; i < V; i++) {
        for (ll j = 0; j < E; j++) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost and d[e.from] != 1e16) {
                d[e.to] = d[e.from] + e.cost;
                if (i == V - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

/*
void warshall_floyd() {
    for(ll k = 0; k < V; k++) {
        for(ll i = 0; i < V; i++) {
            for(ll j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
*/

int main(){
  cin >> V >> E;
  rep(i,E){
    ll a, b , c; cin >> a >> b >> c;
    es[i].from = a; es[i].to = b; es[i].cost = c;
  }

  vector<ll> ans;
  rep(i,V){
    if(has_negative_loop(i)){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
    rep(j,V){
      ans.pb(d[j]);
    }
  }
  rep(i,V){
    rep(j,V){
      if(ans[i * V + j] == 1e16) cout << "INF";
      else cout << ans[i * V + j];
      if(j < V - 1) cout << " ";
    }
    cout << endl;
  }

}

