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

    int v,e;
    cin >> v >> e;

    vector<vector<int> > min_cost(v,vector<int>(v,LINF));

    rep(i,e){
        int s,t,d;
        cin >> s >> t >> d;
        min_cost[s][t] = d;
    }

    auto WarshallFloyd = [&](){
        rep(i,v){
            min_cost[i][i] = 0;
        }
        rep(i,v){
            rep(j,v){
                rep(k,v){
                    if(min_cost[j][i] == LINF || min_cost[i][k] == LINF) continue;
                    if(chmin(min_cost[j][k], min_cost[j][i] + min_cost[i][k]) && j == k){
                        cout << "NEGATIVE CYCLE\n";
                        exit(0);
                    }
                }
            }
        }
        return;
    };

    WarshallFloyd();

    rep(i,v){
        rep(j,v){
            if(j != 0){
                cout << ' ';
            }
            if(min_cost[i][j] == LINF){
                cout << "INF";
            }else{
                cout << min_cost[i][j];
            }
        }
        cout << '\n';
    }

    return 0;
}
