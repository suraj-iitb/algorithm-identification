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

bool Visitable[105][105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    constexpr ll inf = 1e+15;
    vector<vector<ll>> dp(V, vector<ll>(V, inf));
    vector<tuple<int, int, int>> es;
    for(int i = 0; i < E; ++i){
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
        Visitable[s][t] = true;
        es.emplace_back(s, t, d);
    }

    vector<ll> dist(V, 0);
    for(int i = 0; i < V; ++i){
        bool update = false;
        for(auto tup : es){
            int s, t, d;
            tie(s, t, d) = tup;
            if(chmin(dist[t], dist[s] + d)) update = true;
        }
        if(i == V - 1 && update){
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }

    for(int i = 0; i < V; ++i){
        dp[i][i] = 0;
        Visitable[i][i] = true;
    }
    for(int k = 0; k < V; ++k){
        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j){
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
                Visitable[i][j] |= Visitable[i][k] & Visitable[k][j];
            }
        }
    }
    
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            if(Visitable[i][j]) cout << dp[i][j];
            else    cout << "INF";
            cout << ((j == V - 1) ? '\n' : ' ');
        }
    }
}
