#include <bits/stdc++.h>
//#include <vector>
//#include <iostream>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

struct Edge {
    int to;
    int cost;
};

const int MAXV = 100010;
const int INF = 1001001001;

int V, E, r;
vector<vector<Edge>> g(MAXV);

void dijkstra() {
    vi d(V, INF);
    d[r] = 0;

    // int 型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({r, 0});

    while(!q.empty()) {
        auto p = q.top(); q.pop();

        int from = p.first;

        rep(i, g[from].size()) {
            auto v = g[from][i];
            int to = v.to;
            int cost = v.cost;

            if(d[to] > d[from] + cost){
                d[to] = min(d[to], d[from] + cost);
                q.push({to, d[to]});
            }
        }
    }

    rep(i, V) {
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}

int main() {
    cin >> V >> E >> r;
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(Edge{t, d});
    }

    dijkstra();

    return 0;
}

