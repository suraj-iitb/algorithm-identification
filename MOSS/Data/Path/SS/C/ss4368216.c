#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll INF = 1e18;
    
    ll v,e,r;
    cin >> v >> e >> r;

    vector<vector<pair<ll,ll>>> graph(v);
    for(i = 0;i < e;++i){
        ll s,t,d;
        cin >> s >> t >> d;
        graph.at(s).emplace_back(d, t);
        //graph.at(t).emplace_back(d, s);
    }

    priority_queue<pair<ll,ll>> pq;
    vector<ll> vdist(v,INF);
    ll top = r;
    vdist.at(top) = 0;
    pq.emplace(0, top);
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        ll now = x.second;
        ll dist = -x.first;
        if(vdist.at(now) < dist) continue;
        for(i = 0;i < graph.at(now).size();++i){
            ll next = graph.at(now).at(i).second;
            ll nd = dist + graph.at(now).at(i).first;
            if(vdist.at(next) > nd){
                vdist.at(next) = nd;
                pq.emplace(-nd, next);
            }
        }
    }
    for(i = 0;i < v;++i){
        if(vdist.at(i) == INF) cout << "INF" << endl;
        else cout << vdist.at(i) << endl;
    }

    return 0;
}
