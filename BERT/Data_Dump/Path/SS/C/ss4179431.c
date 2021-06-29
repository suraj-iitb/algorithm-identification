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

template<typename T> //最大公約数
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T> //最小公倍数
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

struct edge
{
    int to, cost;
};


int main(){
    int V,E,r; cin >> V >> E >> r;
    vector<vector<edge> > g(V);
    vector<int> Cost(V, MM);
    for (int i = 0; i < E; i++){
        int s,t,d; cin >> s >> t >> d;
        edge now; now.to = t; now.cost = d;
        g[s].push_back(now);
    }

    queue<int> que;
    que.push(r);
    Cost[r] = 0;
    while (que.size()){
        int pos = que.front();
        que.pop();
        for (int i = 0; i < g[pos].size(); i++){
            edge To = g[pos][i];
            if (Cost[pos] + To.cost < Cost[To.to]){
                Cost[To.to] = Cost[pos] + To.cost;
                que.push(To.to);
            }
        }
    }
    for (int i = 0; i < V; i++){
        if (Cost[i] == MM) cout << "INF" << endl;
        else cout << Cost[i] << endl;
    }
}
