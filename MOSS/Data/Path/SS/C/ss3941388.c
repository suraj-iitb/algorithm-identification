#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<ll, int> P;

ll INF = 1LL << 50;

struct edge{
    int to;
    ll cost;
};

/////////////////////////////////////////////////////////////////////////

class GraphD{
public:
    int N;
    vector<ll> d;
    vector<vector<edge>> G;

    GraphD(int n){
        N = n;
        d.resize(N, INF);
        G.resize(N, vector<edge>(0));
    }

    void makeEdge(int s, int t, ll c){
        G[s].push_back(edge{t, c});
    }

    void dijkstra(int s){
        fill(d.begin(), d.end(), INF);
        priority_queue<P, vector<P>, greater<P>> que;
        d[s] = 0;
        que.push(P(0, s));

        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;

            for(int i = 0; i < (int)G[v].size(); i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }

    ll getCost(int t){
        return d[t];
    }
};

///////////////////////////////////////////////////////////////////////////

int main(){
    int N, M, s;
    cin >> N >> M >> s;

    GraphD g = GraphD(N);
    for(int i = 0; i < M; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g.makeEdge(a, b, c);
    }

    g.dijkstra(s);

    for(int i = 0; i < N; i++){
        ll x = g.getCost(i);
        if(x == INF){
            cout << "INF" << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
    /*
    How to use
    インスタンスを作成
    P, edge, INFを定義する
    辺を入力してmakeEdge
    始点sを入力してdijkstra
    d[i]にsからiへの最小コストが入っています
    */
}
