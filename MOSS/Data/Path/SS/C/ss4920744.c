#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000000000
#define endl '\n'
#define int long long
#define mp make_pair
using namespace std;
//using namespace atcoder;
using P = pair<int,int>;
template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << H << " "; debug_out(T...); }
#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif
vector<vector<P>> Graph;
int V, E, start;
vector<int> dist;

void Dijkstra() {
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(start, 0));
    dist[start] = 0;
    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        int now_node = now.first;
        int now_weight = now.second;
        for(auto nx : Graph[now_node]) {
            int nx_node = nx.first;
            int nx_weight = nx.second;
            if(dist[nx_node] == INF) {
                dist[nx_node] = dist[now_node] + nx_weight;
                pq.push(P(nx_node, nx_weight));
            }
            if(dist[nx_node] > dist[now_node] + nx_weight) {
                dist[nx_node] = dist[now_node] + nx_weight;
                pq.push(P(nx_node, nx_weight));
            } else {
                continue;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> V >> E >> start;
    vector<int> copy(V+1, INF);
    dist = copy;
    vector<vector<P>> G(V+1);
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(P(t, d));
    }
    Graph = G;
    Dijkstra();
    rep(i, V) {
        if(dist[i] == INF) {
            cout << "INF" << endl;
        } else
            cout << dist[i] << endl;    
    }
}
