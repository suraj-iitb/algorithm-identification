#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
#define INF 1e9;
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<int,int> P;
struct Node{
    vector<P> edges;
    bool done;
    int cost;
};
int V,E,R;
vector<Node> nodes(100010);
priority_queue<P,vector<P>,greater<P>> q;
void dijkstra(){
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int v = p.second;
        if (nodes[v].done) continue;
        nodes[v].done = true;
        for (P e:nodes[v].edges){
            if(nodes[e.first].cost > nodes[v].cost + e.second){
                nodes[e.first].cost = nodes[v].cost + e.second;
                q.push(P(nodes[e.first].cost,e.first));
            }
        }
    }
}
int main(){
    cin >> V >> E >> R;
    int s,t,d;
    rep (i,100010){
        nodes[i].done = false;
        nodes[i].cost = INF;
    }
    rep(i,E){
        cin >> s >> t >> d;
        nodes[s].edges.push_back(P(t,d));
    }
    nodes[R].cost = 0;
    q.push(P(0,R));
    dijkstra();
    rep(i,V){
        if (nodes[i].cost != 1000000000){
            PRINT(nodes[i].cost);
        }
        else PRINT("INF");
    }
}
