#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

using ll = long long;
using ull = uint64_t;
using P = pair<int, int>;
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

template<class T>
inline bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<P>> graph(V);
    for(int i = 0; i < E; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].emplace_back(t, d);
    }
    
    constexpr ll inf = 1e+13;
    vector<ll> dist(V, inf);
    using Pl = pair<ll, int>;
    priority_queue<Pl, vector<Pl>, greater<Pl>> que;
    dist[r] = 0;
    que.emplace(0, r);
    while(!que.empty()){
        ll d = que.top().first;
        int from = que.top().second;
        que.pop();
        if(d > dist[from])  continue;
        for(P e : graph[from]){
            int to = e.first, cost = e.second;
            if(chmin(dist[to], dist[from] + cost)){
                que.emplace(dist[to], to);
            }
        }
    }
    
    for(int i = 0; i < V; ++i){
        if(dist[i] == inf)  cout << "INF\n";
        else    cout << dist[i] << '\n';
    }
}
