#include <bits/stdc++.h>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
const ll INF = 1000000000000000;
const ll dx[4] = {1,0,-1,0};
const ll dy[4] = {0,1,0,-1};
ll mod(ll x,ll m){return x & m;}
ll modinv(ll a,ll m){
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll a, ll n, ll m) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}
ll yaku(ll x){
    ll cnt = 0;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(i == x / i) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}
ll modwaru(ll a, ll b, ll m){
    a %= m;
    return a * modinv(b, m) % m;
}
ll gcd(ll x, ll y){
    if(x % y == 0)return y;
    else return gcd(y, x % y); 
}
struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    ll V, E, r;
    cin >> V >> E >> r;
    vector<ll> dist(V, INF);
    vector<bool> kita(V, false);
    vector<vector<pair<ll,ll>>> gra(V);
    for(int i = 0; i < E; i++){
        ll s, t, d;
        cin >> s >> t >> d;
        gra[s].push_back(make_pair(t, d));
    }
    dist[r] = 0;
    //　ばしょ　おもさ
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pri;
    pri.push(make_pair(r,0));
    while(!pri.empty()){
        pair<ll,ll> f = pri.top();
        pri.pop();
        if(dist[f.first] < f.second) continue;
        kita[f.first] = true;
        for(pair<ll,ll> a : gra[f.first]){
            ll s = a.first, d = a.second;
            if(dist[s] > dist[f.first] + d){
                dist[s] = dist[f.first] + d;
                pri.push(make_pair(s, dist[s]));
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dist[i] == INF){
            cout << "INF" << endl;
            continue;
        }
        cout << dist[i] << endl;
    }
}
