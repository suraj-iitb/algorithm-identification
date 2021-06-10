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


struct edge{
    int to, cost;
    edge(int To, int Cost): to(To), cost(Cost){};
};

void initialFromGraphList_Cost(std::vector<std::vector<edge>>& G, std::vector<std::vector<long long>>& d){
    int V(G.size());
    d.resize(V);
    for(int i(0); i < V; ++i){
        d[i].resize(V, LINF);
        d[i][i] = 0;
    }
    for(int i(0); i < V; ++i){
        for(auto& e: G[i])
            d[i][e.to] = e.cost;
    }
}

void warshallFloyd(std::vector<std::vector<long long>>& d){
    int V(d.size());
    for(int k(0); k < V; ++k)
        for(int i(0); i < V; ++i)
            for(int j(0); j < V; ++j)
                chmin(d[i][j], d[i][k] + d[k][j]);
}

bool find_negative_loop(std::vector<std::vector<long long>>& d){
    //warshallFloyd()をしてから
    int V(d.size());
    for(int i(0); i < V; ++i)
        if(d[i][i] < 0) return true;
    return false;
}

int main(){
    int V, E; std::cin >> V >> E;
    std::vector<std::vector<edge>> G(V);
    {
        int s, t, d; 
        for(int i(0); i < E; ++i){
            std::cin >> s >> t >> d;
            G[s].emplace_back(t, d);
        }
    }
    std::vector<std::vector<long long>> d;
    initialFromGraphList_Cost(G, d);
    warshallFloyd(d);
    if(find_negative_loop(d)){
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return 0;
    }
    for(int i(0); i < V; ++i){
        for(int j(0); j < V; ++j){
            if(j) std::cout << " ";
            if(d[i][j] > 1'980'000'000) std::cout << "INF";
            else std::cout << d[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}

