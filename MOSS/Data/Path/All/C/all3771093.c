#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

const int MAX = 100;
const ll INF = (1LL << 32);

int n;
ll d[MAX][MAX];

void warshallFloyd() {
    rep(k, n) {
        rep(i, n) {
            if(d[i][k] == INF) {
                continue;
            }
            rep(j, n) {
                if(d[k][j] == INF) {
                    continue;
                }

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int e, u, v, c;
    cin >> n >> e;

    rep(i, n) {
        rep(j, n) {
            d[i][j] = ( (i == j) ? 0 : INF );
        }
    }

    rep(i, e) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    warshallFloyd();

    bool negative = false;
    rep(i, n) {
        if(d[i][i] < 0) {
            negative = true;
        }
    }

    if(negative) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        rep(i, n) {
            rep(j, n) {
                if(j) {
                    cout << " ";
                }
                if(d[i][j] == INF) {
                    cout << "INF";
                }
                else {
                    cout << d[i][j];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
