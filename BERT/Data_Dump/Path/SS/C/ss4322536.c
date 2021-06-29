#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>
#include <cassert>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using uInt = long long unsigned int;
using Double = long double;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
template<typename T = int,
        typename E = int,
        typename F = function<T(T, E)>,
        typename Compare = function<T(T, T) >>
class Dijkstra {
public:
    Int N;
    T s_value;
    T init_value;
    F f;
    Compare cmp;

    vector<T> dist;
    vector<vector<pair<int, E>>>
            G; // first : index, second : E


    Dijkstra(Int N, T s_value = 0, T init_value = INF,
             F f = [](T l, T r) { return l + r; },
             Compare cmp = [](T l, T r) { return l > r; }
    ) : N(N), s_value(s_value), init_value(init_value), f(f), cmp(cmp) {
        dist.resize(N, init_value);
        G.resize(N);
    }

    void add_edge(int f, int t, E e) {
        G[f].push_back(make_pair(t, e));
//        G[t].push_back(make_pair(f, e));
    }

    void compute(int s) {
        using P = pair<T, int>;
        auto pq_cmp = [this](P l, P r) -> bool {
            return cmp(l.first, r.first);
        };
        priority_queue<P, vector<P>, decltype(pq_cmp)> que(pq_cmp);
        fill(dist.begin(), dist.end(), init_value);
        dist[s] = s_value;

        que.push(P(dist[s], s));

        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;

//            if (!cmp(dist[v], p.first) && (dist[v] != p.first)) continue;
            if (cmp(p.first, dist[v])) continue;

            for (int i = 0; i < G[v].size(); i++) {
                int to_idx = G[v][i].first;
                E to_e = G[v][i].second;

                if (cmp(dist[to_idx], f(dist[v], to_e)) && !(dist[to_idx] == init_value && dist[v] == init_value)) {
                    dist[to_idx] = f(dist[v], to_e);
                    que.push(P(dist[to_idx], to_idx));
                }
            }
        }
    }

    T get_value(int v) {
        return dist[v];
    }


};


class Solve {
public:
    void solve() {
        Int V, E, r;
        cin >> V >> E >> r;

        Dijkstra<> dij(V);

        for (int i = 0; i < E; ++i) {
            Int a, b, d;
            cin >> a >> b >> d;
            dij.add_edge(a, b, d);
        }

        dij.compute(r);

        for (int i = 0; i < V; ++i) {
            Int tmp = dij.get_value(i);
            if (tmp == INF) {
                cout << "INF" << endl;
            } else {
                cout << tmp << endl;
            }
        }
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    Solve().solve();


    return 0;
}

