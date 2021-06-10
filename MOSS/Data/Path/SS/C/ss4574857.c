#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
int n, m, x, y,z,w,h, sum, ans;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
struct edge {
    int to;
    ll cost;
    edge(int to, ll cost) : to(to), cost(cost) {}
};
vector<vector<edge>> G(100000);
using  p = pair<ll, int>;
vector<ll> d(100000,INF);
void dijkstra(int s) {
    priority_queue<p, vector<p>, greater<p> >pq;
    d[s] = 0;
    pq.push({ 0,s });
    while (!pq.empty()) {
        p now = pq.top(); pq.pop();
        int v = now.second;
        if (d[v] < now.first) continue;
        for (edge e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                pq.push(p(d[e.to], e.to));
            }
        }
    }
}
int main(void) {
    cin >> n >> m >> w;
    rep(i, m) {
        cin >> x >> y >> z;
        G[x].push_back({ y,z });
    }
    dijkstra(w);
    rep(i, n) {
        if (d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
