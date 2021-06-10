#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include <set>
#include<unordered_map>
#include<stack>
#include<string>
#include<iomanip>
#include<algorithm>
#include<functional>
#include<cstring>
#include<utility>
#include<math.h>
#include <bitset>
using namespace std;



/**** Type Define ****/

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;

/**** Const List   ****/
const ll INF = 1LL << 60;
const ll mod =  1000000007;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};
const ll NCK_MAX = 510000;



ll v,e,r;
vector<P> edge[100001];
ll cost[100001];

int main(){
  cin>>v>>e>>r;
  for(ll i=0;i<e;i++){
    ll ss,tt,dd;
    cin>>ss>>tt>>dd;
    edge[ss].push_back(P(tt,dd));
  }
  for(ll i=0;i<v;i++){
    cost[i]=INF;
  }
  priority_queue<P,vector<P>,greater<P>> q;
  q.push(P(0,r));
  cost[r]=0;
  while(!q.empty()){
    ll ncos=q.top().first;
    ll now=q.top().second;
    q.pop();
    if(cost[now]<ncos)continue;
    //cout<<ncos<<" "<<now<<endl;
    for(ll i=0;i<edge[now].size();i++){
      if(cost[edge[now][i].first]>cost[now]+edge[now][i].second){
        cost[edge[now][i].first]=cost[now]+edge[now][i].second;
        q.push(P(cost[edge[now][i].first],edge[now][i].first));
      }
    }
  }
  for(ll i=0;i<v;i++){
    if(cost[i]==INF){
      cout<<"INF"<<endl;
    }else{
      cout<<cost[i]<<endl;
    }
  }
}

