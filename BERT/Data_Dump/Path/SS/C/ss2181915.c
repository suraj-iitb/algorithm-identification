#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 1000000000;
using namespace std;

class Edge{
    public:
        int to, cost;
        Edge(int to, int cost) : to(to) ,cost(cost) {}
};

class Node{
    public:
        int dis;
        bool isUsed;
        Node(){
            this->dis = INF;
            this->isUsed = 0;
        }
};

typedef vector<vector<Edge>> AdjList;

int dijkstra(AdjList g, int start, int n){
    vector<Node> node(n);
    priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, start));
    node[start].dis = 0;

    pair<int, int> u;
    while(not q.empty()){
        u = q.top(); q.pop();
        int current = u.second;
        node[current].isUsed = 1;

        rep(i,g[current].size()){
            int next = g[current][i].to;
            if(node[next].isUsed == 0){
                if(node[next].dis > node[current].dis + g[current][i].cost){
                    node[next].dis = node[current].dis + g[current][i].cost;
                    q.push(make_pair(node[next].dis, next));

                }
            }
        }
    }
    for(auto it:node){
        if(it.dis == INF) cout << "INF" << endl;
        else cout << it.dis << endl;
    }
    return 0;
}

int main(){
    int v, e, r;
    cin >> v >> e >> r;

    AdjList g(v);
    rep(i,e){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
    }
    dijkstra(g, r, v);

}
