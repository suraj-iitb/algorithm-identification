#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;
template <typename T> using V = vector<T>;
template <typename T> using VV = vector<V<T>>;

const i64 INF = 5e15;
 
template<typename T>
class Dijk {
private:
    template <typename U> using Edge = pair<i64, U>;
    template <typename U> using Edges = vector<Edge<U>>;
    template <typename U> using PQ = priority_queue<pair<i64, U>, vector<pair<i64, U>>, function<bool(pair<i64, U>, pair<i64, U>)>>;
     
    vector<Edges<T>> edges;
    T inf;
    T identity_ele;
         
public:
    Dijk(const vector<Edges<T>> &edges, T inf, T identity_ele)
        : edges(edges),
          inf(inf),
          identity_ele(identity_ele) {}
 
    vector<T> dijk(i64 start) {
        vector<T> d(edges.size(), inf);
        d[start] = identity_ele;
        PQ<T> q([&](const Edge<T> &a, const Edge<T> &b) {return a.second > b.second;});
        q.push(make_pair(start, 0));
        while(q.size()) {
            i64 now;
            T dis;
            tie(now, dis) = q.top();
            q.pop();
            if(d[now] < dis) {
                continue;
            }
            for(const auto &e : edges[now]) {
                i64 nxt;
                T cost;
                tie(nxt, cost) = e;
                if(d[nxt] == inf || dis + cost < d[nxt]) {
                    d[nxt] = dis + cost;
                    q.push(make_pair(nxt, dis + cost));
                }
            }
        }
        return d;
    }
};
 
int main() {
    i64 N, M, R;
    cin >> N >> M >> R;
    VV<pair<i64, i64>> edges(N);
    for(i64 i = 0; i < M; i++) {
        i64 a, b, c;
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
    }
    auto dist = move(Dijk<i64>(edges, INF, 0).dijk(R));
    for(i64 d : dist) {
        if(d == INF) cout << "INF";
        else cout << d;
        cout << '\n';
    }
    return 0;
}

