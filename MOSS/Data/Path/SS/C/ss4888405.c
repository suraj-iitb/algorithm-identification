#include <bits/stdc++.h>
#include<math.h>
#include<algorithm>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll, ll> ;
using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vl = vector<ll> ;
using vvl = vector<vector<ll>> ; 
using vs = vector<string> ; 
using vvs = vector<vector<string>> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007
struct Edge {
    int to, d ;
};
int main() { 
    int v, e, r ;
    cin >> v >> e >> r ; 
    vector<vector<Edge>> vec (v) ;
    rep(i, e){
        int s, t, d ;
        cin >> s >> t >> d ;
        vec[s].push_back(Edge{t, d}) ;
    }
    vector<ll> ds (v, INF) ;
    priority_queue<P, vector<P>, greater<P>> que ;
    que.emplace(0, r) ;
    while(!que.empty()){
        P p = que.top() ;
        que.pop() ;
        if(p.first >= ds[p.second]) continue ;
        ds[p.second] = p.first ; 
        int k = vec[p.second].size();
        rep(i, k){
            int t = vec[p.second][i].to ;
            int cost = vec[p.second][i].d ; 
            if(p.first + cost < ds[t]) {
                que.emplace(p.first + cost, t) ;
            }
        }
    }
    rep(i, v){
        if(ds[i] > 1e15) cout << "INF" << endl ; 
        else {
            cout << ds[i] << endl ; 
        }
    }
}
