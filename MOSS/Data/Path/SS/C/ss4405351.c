#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int a[]={1,-1,5,-5,10,-10};

int main() {
    ll V,E,r;
    cin >> V >> E >> r;
    vector<vector<pair<ll,ll>>> G(V);
    for(ll i=0;i<E;i++){
        ll x,y,cost;
        cin >> x >> y >> cost;
        G[x].push_back({y,cost});
    }
    vector<ll> dist(V,INF),used(V,0);
    dist[r]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,r});
    while(!pq.empty()){
        ll pos,d;
        pos = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if(used[pos]==1)continue;
        used[pos]=1;
        for(auto &x:G[pos]){
            if(dist[x.first]>d+x.second){
                dist[x.first] = d+x.second;
                pq.push({dist[x.first],x.first});
            }
        }
    }
    for(auto &x:dist){
        if(x!=INF)cout << x << endl;
        else cout << "INF" << endl;
    }
}
