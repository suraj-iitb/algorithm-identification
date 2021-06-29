#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>
#include <random>
#include <cstring>

#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back

using namespace std;
using ll = long long;


const ll mod = 1000000007;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
// bool debug=false;

/*---------------------------------------------------*/

ll INF = 100000000000;

struct Edge {
    int to;
    ll cost;
};

// typedef pair<int, int> P; と同じ意味
// firstには最短距離、secondには頂点の番号が入る
using P = pair<ll, ll>;

int main() {
    ll s, V, E;
    cin >> V >> E >> s;

    vector<Edge> G[V];
    for(int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({t, d});
    }
    priority_queue<P, vector<P>, greater<P>> que;
    ll d[V];
    for(int i = 0; i < V; i++) {
        d[i] = INF;
    }

    // ↓ここからダイクストラ法↓
    d[s] = 0;
    que.push(P(0, s));
    
    while(que.size()) {
        P p = que.top(); que.pop();
        ll cost = p.first;
        int v = p.second;
        if(d[v] < cost) continue;
        for(int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    for(int i = 0; i < V; i++) {
        if(d[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << d[i] << endl;
        }
    }
    return 0;
}


