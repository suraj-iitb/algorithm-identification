#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
// #define INF 1LL<<60

const int INF = 1e9;

struct edge {
    int to;
    int d;
};

int main() {
    int N, M, r;
    cin >> N >> M >> r;
    vector< vector<edge> > edges(N, vector<edge>());
    REP(i, M) {
        int s, t, d;
        cin >> s >> t >> d;
        edge e = {t, d};
        edges[s].push_back(e);
    }

    vector<int> dist(N, INF);
    queue<int> que;
    que.push(r);
    dist[r] = 0;

    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        for(edge e: edges[cur]) {
            if(dist[e.to] > dist[cur] + e.d) {
                dist[e.to] = dist[cur] + e.d;
                que.push(e.to);
            }
        }
    }

    REP(i, N) {
        if(dist[i] < INF) {
            cout << dist[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }

    return 0;
}
