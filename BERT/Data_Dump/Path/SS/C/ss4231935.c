#pragma GCC optimize("Ofast")
  
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <tuple>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <numeric>
#include <math.h>
#include <random>

using namespace std;
  
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define setout(n,x) setw(n+1) << setfill(x)
#define Fixed fixed << setprecision(14)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 
 
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
 
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;

int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}

signed main(void){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int v,e,r;
    cin >> v >> e >> r;

    vector<vector<pii> > g(v);

    rep(i,e){
        int s,t,d;
        cin >> s >> t >> d;
        g[s].emplace_back(t,d);
    }

    auto Dijkstra = [&](int s){
        vector<int> min_cost(v,INF);
        min_heap<pii> pq;
        min_cost[s] = 0;
        pq.emplace(0,s);

        while(!pq.empty()){
            int now_cost,now_node;
            tie(now_cost,now_node) = pq.top();
            pq.pop();
            if(now_cost > min_cost[now_node]) continue;
            for(auto e : g[now_node]){
                int next_node,cost;
                tie(next_node,cost) = e;
                if(chmin(min_cost[next_node],min_cost[now_node] + cost)){
                    pq.emplace(min_cost[next_node],next_node);
                }
            }
        }
        return min_cost;
    };

    for(auto e : Dijkstra(r)){
        if(e == INF){
            cout << "INF\n";
        }else{
            cout << e << '\n';
        }
    }

    return 0;
}
