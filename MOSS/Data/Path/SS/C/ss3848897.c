#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}
struct edge {
    ll to,cost;
};
vector<vector<edge> > g(100010);
int main(){
    ll V,E,r; cin >> V >> E >> r;
    vector<ll> dist(V,INF);
    for (int i = 0; i < E; i++){
        ll s,t,d; cin >> s >> t >> d;
        g[s].push_back({t,d});
    }
    queue<ll> que;
    dist[r] = 0;
    que.push(r);
    while (que.size()){
        ll now = que.front();
        que.pop();
        for (auto e : g[now]){
            if (dist[e.to] > dist[now] + e.cost){
                dist[e.to] = dist[now] + e.cost;
                que.push(e.to);
            }
        }
    }
    for (int i = 0; i < V; i++){
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
