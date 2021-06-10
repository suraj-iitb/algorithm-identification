#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
const ll INF = 100100100100;

int v, e;

int main()
{
    cin >> v >> e;
    vector<vector<ll>> D(v, vector<ll>(v, INF));
    rep(i, e)
    {
        int s, t;
        ll d;
        cin >> s >> t >> d;
        D[s][t] = d;
    }
    rep(k, v) rep(i, v) rep(j, v)
    {
        if (D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j])
        {
            D[i][j] = D[i][k] + D[k][j];
        }
    }
    rep(i, v)
    {
        if (D[i][i] < 0)
        {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
        D[i][i] = 0;
    }
    rep(i, v) rep(j, v)
    {
        if (D[i][j] == INF)
            cout << "INF";
        else
            cout << D[i][j];
        if (j == v - 1)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}
