#if 0
50分
Bellman_Fordで無限をlong longの最大値にしたことで、overflow対策が
必要になったことは事前に気づくことができたが、Dijkstraで閉路があると
無限ループになることが盲点だった。
#endif
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <queue>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
ll ll_max = numeric_limits<ll>::max();
ll ll_min = numeric_limits<ll>::min();
int int_max = numeric_limits<int>::max();
int int_min = numeric_limits<int>::min();

int V, E, r, s, t, d;
// vector<pair<pair<int, int>, int> > edges1;
pair<vector<int>, vector<int> > edges2[100000];
int D[100000];
int checked[100000] = {};

// void Bellman_Ford() {
//     rep(v, V) D[v] = int_max;
//     D[r] = 0;
//     rep(v, V - 1) {
//         bool updated = false;
//         for (auto edge : edges1) {
//             s = edge.first.first;
//             t = edge.first.second;
//             d = edge.second;
//             // overflow対策
//             if (min(D[t], D[s] + d) > 0) {
//                 updated = true;
//                 D[t] = min(D[t], D[s] + d);
//             }
//         }
//         if (!updated) return;
//     }
// }

void Dijkstra() {
    rep(v, V) D[v] = int_max;
    D[r] = 0;
    // vector<int> fixed;
    priority_queue<pair<int, int> > Q;
    Q.push(make_pair(0, r));
    while (Q.size() != 0) {
        pair<int, int> top = Q.top();
        Q.pop();
        // すでに確定済み頂点なら飛ばす。
        if (checked[top.second] == 1) 
            continue;
        rep(i, edges2[top.second].first.size()) {
            int t = edges2[top.second].first[i];
            int d = edges2[top.second].second[i];
            D[t] = min(D[t], d - top.first);
            // 距離をマイナスで与えて、近いものから取り出すようにする。
            Q.push(make_pair(-D[t], t));
        }
        checked[top.second] = 1;
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> V >> E >> r;
    rep(e, E) {
        cin >> s >> t >> d;
        // edges1.push_back(make_pair(make_pair(s, t), d));
        edges2[s].first.push_back(t);
        edges2[s].second.push_back(d);
    }
    // cout << "input done" << endl;
    // Bellman_Ford();
    Dijkstra();
    rep(v, V) {
        if (D[v] == int_max) cout << "INF" << endl;
        else cout  << D[v] << endl;
    }

    return 0;
}
