#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define int long long
#define pb push_back

typedef long long ll;

using namespace std;

const int base = 36;
const int base2 = 316;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;
const ll INF = 1e18;

int dist[101][101];
int n, m;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("out.out", "w", stdout);
//    freopen("5.inp", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                dist[i][j] = INF;

    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++)
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF)
                cout << "INF";
            else
                cout << dist[i][j];

            if (j + 1 < n)
                cout << " ";
        }

        cout << "\n";
    }
}
