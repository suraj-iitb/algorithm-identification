#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
struct edge{ int to, cost; };
const int INF = 1001001001;
const int MAX_V = 200005;
int V,E;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        for(int i=0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> V >> E;
    int r; cin >> r;
    rep(i,E){
        int from,to,cost;
        cin >> from >> to >> cost;
        edge e1, e2;
        e1.to = to; e1.cost = cost;
        e2.to = from; e2.cost = cost;
        G[from].push_back(e1);
        // G[to].push_back(e2);
    }

    dijkstra(r);

    rep(i, V){
        if(d[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << d[i] << endl;
        }
    }

    return 0;
}
