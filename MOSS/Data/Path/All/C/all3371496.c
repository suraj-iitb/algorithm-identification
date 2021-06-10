#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define LL long long
#define endl '\n'
using namespace std;

static const int MAX = 100;
static const int long long INFTY = (1LL << 32);

int n;
LL d[MAX][MAX];

void floyd()
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (d[i][k] == INFTY) {  // d[i][k]は通らないのでスキップ
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (d[k][j] == INFTY) {  // d[k][j]を通らないのでスキップ
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // (i, j)への経路(前回までは最短)と,(i, k)->(k, j)を比較する
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int e, u, v, c;
    cin >> n >> e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = ((i == j)? 0 : INFTY);
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    floyd();

    bool negative = false;
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            negative = true;
        }
    }

    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                if (d[i][j] == INFTY) {
                    cout << "INF";
                } else {
                    cout << d[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
