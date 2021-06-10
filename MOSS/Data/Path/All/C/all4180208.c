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

struct Edge
{
    int to, cost;
};
struct Node
{
    int from, to, cost;
};



vector<vector<Edge> > g;
vector<Node> node;
int V, E;
bool Find_Negative_Cycle(){
    vector<ll> dist(V, INF);
    int num = 0;
    while (true){
        if (g[num].size() > 0){
            dist[num] = 0;
            break;
        }
    }
    for (int i = 0; i < V; i++){
        for (int j = 0; j < node.size(); j++){
            Node n = node[j];
            if (dist[n.from] != MM & dist[n.from] + n.cost < dist[n.to]){
                dist[n.to] = dist[n.from] + n.cost;
                if (i == V-1){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    cin >> V >> E;
    ll dist[V][V];
    g.resize(V);
    node.resize(E);
    for (int i = 0; i < E; i++){
        int s, t, d; cin >> s >> t >> d;
        Edge e; e.to = t; e.cost = d;
        Node n; n.from = s, n.to = t, n.cost = d;
        g[s].push_back(e);
        node.push_back(n);
    }
    if (V == 1){
        cout << 0 << endl;
        return 0;
    }
    if (E == 0){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (i == j){
                    cout << 0;
                } else {
                    cout << "INF";
                }
                if (j != V-1) cout << ' ';
            }
            cout << endl;
        }
        return 0;
    }
    if (Find_Negative_Cycle()){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int u = 0; u < V; u++){
        //uは初期位置
        for (int i = 0; i < V; i++){
            dist[u][i] = INF;
        }
        dist[u][u] = 0;
        queue<int> que;
        que.push(u);
        while (que.size()){
            int Front = que.front();
            que.pop();
            for (int i = 0; i < g[Front].size(); i++){
                Edge es = g[Front][i];
                if (dist[u][Front] != INF && dist[u][es.to] > dist[u][Front] + es.cost){
                    dist[u][es.to] = dist[u][Front] + es.cost;
                    que.push(es.to);
                }
            }
        }
    }
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF){
                cout << "INF";
            } else {
                cout << dist[i][j];
            }
            if (j != V-1) cout << ' ';
        }
        cout << endl;
         
    }
}
