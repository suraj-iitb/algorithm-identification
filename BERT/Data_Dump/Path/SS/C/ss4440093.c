#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
# define ll int64_t
# define str string
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define PI 3.141592653589793
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
using namespace std;

#define INF 2000000000
#define MAX_V 10

struct Info{
    Info(ll arg_to,ll arg_cost){
        to = arg_to;
        cost = arg_cost;
    }
    bool operator<(const struct Info &arg) const{
            return cost > arg.cost;
    };
    ll to,cost;
};

bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll modpow(ll a,ll n,ll mod1) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod1;
        a = a*a%mod1;
        n >>= 1;
    }
    return res;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) (x*=i)%=mod;
    return x;
}

ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b,a%b));
}

ll lcm(ll a,ll b){
   return a/gcd(a,b)*b;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll v,e,r;
    cin>>v>>e>>r;
    
    ll mincost[v];
    rep(i,v) mincost[i]=INF;
    mincost[r]=0;
    
    vector<Info> edges[v];
    
    rep(i,e){
        ll s,t,d;
        cin>>s>>t>>d;
        edges[s].pb(Info(t,d));
    }
    
    priority_queue<Info> q;
    
    rep(i,edges[r].size()){
        if(mincost[edges[r][i].to]>edges[r][i].cost){
            mincost[edges[r][i].to]=edges[r][i].cost;
            q.push(Info(edges[r][i].to,edges[r][i].cost));
        }
    }
    ll minindex = 0;
    while(!q.empty()){
        if(q.top().cost>mincost[q.top().to]) q.pop();
        else{
            minindex=q.top().to;
            q.pop();
        }
        rep(i,edges[minindex].size()){
            if(mincost[edges[minindex][i].to]>mincost[minindex] + edges[minindex][i].cost){
                mincost[edges[minindex][i].to]=mincost[minindex] + edges[minindex][i].cost;
                q.push(Info(edges[minindex][i].to,mincost[edges[minindex][i].to]));
            }
        }
    }
    rep(i,v){
        if(mincost[i]==INF) cout<<"INF"<<endl;
        else cout<<mincost[i]<<endl;
    }
    return 0;
}

