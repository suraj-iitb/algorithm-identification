#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
#define INF (1 << 30)
#define ll long long int

vector<pair<ll, ll> > G[MAX];
ll N, d[MAX];
bool al[MAX];

void dijkstra(ll r){
    priority_queue<pair<ll, ll> > PQ;
    for(ll i=0; i<N; i++){
        d[i] = INF;
        al[i] = false;
    }
    d[r] = 0;
    PQ.push(make_pair(0,r));
    while(!PQ.empty()){
        pair<ll, ll> f = PQ.top(); PQ.pop();
        ll u = f.second;
        al[u] = true;
        if(d[u] < f.first*(-1)) continue;

        for(ll j=0; j<G[u].size(); j++){
            ll v = G[u][j].first;
            if(al[v]) continue;
            if(d[v] > (d[u] + G[u][j].second)){
                d[v] = d[u] + G[u][j].second;
                PQ.push(make_pair(d[v]*(-1), v));
            }
        }
    }
}

int main(){
    ll e, r;
    cin >> N >> e >> r;
    for(ll i=0; i<e; i++){
        ll s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(make_pair(t, w));
    }
    dijkstra(r);
    for(ll i=0; i<N; i++){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}

