#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define ll  long long 
const ll INF=1LL<<60;
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
vector<pair<ll,ll>>s[100001];
ll dis[100001];
ll n;
void dijkstra(ll u){
  priority_queue<pair<ll,ll>>pq;
  rep(i,n)dis[i]=INF;
  dis[u]=0;
  pq.push(make_pair(u,0));
  while(!pq.empty()){
    ll a=pq.top().first;
    ll b=pq.top().second;
    pq.pop();
    if(dis[a]<-b)continue;
    rep(i,s[a].size()){
      ll c=s[a][i].first;
      ll d=s[a][i].second;
      if(dis[c]>dis[a]+d){
        dis[c]=dis[a]+d;
        pq.push(make_pair(c,-dis[c]));
      }
    }
  }
}
int main(){
  ll e,r;cin>>n>>e>>r;
  rep(i,e){
    ll a,b,c;cin>>a>>b>>c;
    s[a].push_back(make_pair(b,c));
  }
  dijkstra(r);
  rep(i,n){
    if(dis[i]==INF)cout<<"INF"<<endl;
    else cout<<dis[i]<<endl;
  }
}
