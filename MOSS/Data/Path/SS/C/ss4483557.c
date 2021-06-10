#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int N, M, r; cin >> N >> M >> r;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b, d; cin >> a >> b >> d;
        G[a].push_back(make_pair(b, d));
    }

    //始点0からの距離d[v] / 到達した頂点を記録するchecked[v]
    //次に到達する候補の中からコストd[v]が小さい順に取り出すpq
    vector<int> d(N, MAX);
    vector<bool> checked(N, false);
    priority_queue<pair<int, int>> pq;
    d[r] = 0;
    pq.push(make_pair(0, r));

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        
        //取り出した経路が最短でない場合
        if (d[v] < p.first * (-1)) continue;
        
        checked[v] = true;

        //vに隣接している未到達の頂点の最短経路を更新し、もし更新したらpqに入れる
        for (auto np : G[v]) {
            int nv = np.first;
            if (checked[nv]) continue;

            if (chmin(d[nv], d[v] + np.second)) pq.push(make_pair(d[nv] * (-1), nv));
        }
    }

    for (int i = 0; i < N; i++) {
        if (d[i] == MAX) {
            cout << "INF" << endl;
        } else {
            cout << d[i] << endl;
        }
    }

    return 0;
}
