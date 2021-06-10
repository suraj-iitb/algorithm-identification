#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)







using P = pair<ll, ll>;

int main() {
    ll n, m, r;
    cin >> n >> m >> r;
    vector<vector<P>> g(n);
    REP(i, m){
        ll s, t, d;
        cin >> s >> t >> d;
        g[s].push_back({t, d});
    }
    
    vector<ll> dist(n, INF);
    dist[r] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push({0, r});
    while(!que.empty()){
        auto tmp = que.top(); que.pop();
        ll d = tmp.first, now = tmp.second;
        if(dist[now] < d) continue;
        
        for(auto &x : g[now]){
            ll v = x.first, c = x.second;
            if(dist[v] > dist[now] + c){
                dist[v] = dist[now] + c;
                que.push({dist[now] + c, v});
            }
        }
    }
    REP(i, n){
        if(dist[i] != INF) cout << dist[i] << endl;
        else cout << "INF" << endl;
    }
}

