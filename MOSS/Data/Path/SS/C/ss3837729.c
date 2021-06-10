#include<iostream>
#include <iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<tuple>
#include<list>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

struct edge{
    ll to,cost;
};
ll n;
vector<edge>  G[100010];
ll d[100010];

void  dijkstra(int s){
    priority_queue<pii,vector<pii>,greater<pii>> que;
    fill(d,d+n,LLINF);
    d[s]=0;
    que.push(pii(0,s));

    while(!que.empty()){
        pii p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pii(d[e.to],e.to));
            }
        }
    } 
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll e,r;
    cin>>n>>e>>r;
    rep(i,e){
        ll  a,b,c;
        cin >>a>>b>>c;
        G[a].pb({b,c});
    }
    dijkstra(r);
    rep(i,n){
        if(d[i]==LLINF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    return 0;
}
