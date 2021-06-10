#define _USE_MATH_DEFIMES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007;
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}


/*
int V; //頂点数
std::vector<std::vector<edge>> G;  std::vector<int> G;
std::vector<int> d; //sからの距離
*/

struct edge{
    int to, cost;
    edge(int To, int Cost): to(To), cost(Cost){}
};

void dijkstra(std::vector<std::vector<edge>>& G, std::vector<int>& d, int s){
    //pair<int, int> first: 距離　second: 頂点
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> que;
    int V(G.size());
    d.resize(V, INF+3);
    d[s] = 0;
    que.push({0, s});

    while(!que.empty()){
        std::pair<int, int> p(que.top()); que.pop();
        int v(p.second);
        if(d[v] < p.first) continue;
        for(edge &e: G[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
}
int main(){
    int V, E, r; std::cin >> V >> E >> r;
    std::vector<std::vector<edge>> G(V);
    {
        int s, t, d; 
        for(int i(0); i < E; ++i){
            std::cin >> s >> t >> d;
            G[s].emplace_back(t, d);
        }
    }
    std::vector<int> d;
    dijkstra(G, d, r);
    for(int i(0); i < V; ++i){
        if(d[i] > INF) std::cout << "INF";
        else std::cout << d[i];
        std::cout << "\n";
    }
    return 0;
}

