#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e, r; cin >> v >> e >> r;
    vector<vector<P>> G(v);
    rep(i, e) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back(P(d, t)); // {距離, to頂点}の順で保持
    }

    // Pを保持する昇順の優先度付きキューを作成
    // 始点からつながる頂点に対し、距離が短い辺から順に走査していく
    // ∵ すでに最短経路が確定している頂点vについて、vからの距離が
    //    最短の頂点nvについて考えると、vを経由するよりも短い経路が
    //    存在しないので、最短経路（s=>..=>v=>nv）が確定できる
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> d(v, INF);
    que.push(P(0, r));
    d[r] = 0;

    while (!que.empty()) {
        // P p として queの先頭の{距離, 頂点}を取得
        P p = que.top(); que.pop();
        int v = p.second;
        // 頂点vからつながるnvについて走査
        for (const auto& nv: G[v]) {
            // 始点=>vまでの距離 + v=>nvの距離 と、d[nv] の大きさを比較する
            // もしd[nv]のほうが小さければ、別により短い経路があるので探索打ち切り
            if (d[v] + nv.first > d[nv.second]) continue;
            else {
                d[nv.second] = d[v] + nv.first;
                que.push(nv);
            }
        }
    }

    rep(i, v) {
        if (d[i]!=INF) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
}
