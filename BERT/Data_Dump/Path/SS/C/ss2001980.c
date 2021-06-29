#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v){
    if(!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}
//---------

const int MAX_V = 500003;
struct edge{
    int from, to, cost;
    bool operator<(const edge x)const{return cost<x.cost;}
};

vector<edge> G[MAX_V]; //???????????´

void AddEdge(int s,int g,int c){
    G[s].push_back((edge){s, g, c});
}

int vv = MAX_V; //????????°
ll dd[MAX_V];//??????????????¢
void dijkstra(int s){
    fill(dd, dd+vv, 1e11);
    dd[s] = 0;
    priority_queue<P ,vector<P> ,greater<P> > que;
    que.push(pair<int, int>(0, s));

    while(que.size()){
        P p = que.top();que.pop();
        int u = p.second;
        if(dd[u] < p.first) continue;
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(dd[e.to] > dd[u] + e.cost){
                dd[e.to] = dd[u] + e.cost;
                que.push(P(dd[e.to], e.to));
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e >> r;
    rep(i, 0, e){
        int s, t, d;
        cin >> s >> t >> d;
        AddEdge(s, t, d);
    }
    dijkstra(r);
    rep(i, 0, v) {
        if(dd[i] == 1e11) cout << "INF" << endl;
        else cout << dd[i] << endl;

    }
}
