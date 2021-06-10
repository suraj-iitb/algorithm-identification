#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int v, e;
    cin >> v >> e;
    ll m[v][v];

    rep(i, v) rep(j, v) m[i][j] = (i == j ? 0 : INT_MAX);

    rep(i, e)
    {
        int s, t, d;
        cin >> s >> t >> d;
        m[s][t] = d;
    }

    rep(k, v)
    {
        rep(i, v)
        {
            if (m[i][k] == INT_MAX)
                continue;
            rep(j, v)
            {
                if (m[k][j] == INT_MAX)
                    continue;
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }
        }
    }

    bool nega = 0;
    rep(i, v) if (m[i][i] < 0) nega = 1;

    if (nega == 1)
    {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i, v)
    {
        rep(j, v)
        {
            if (m[i][j] == INT_MAX)
            {
                cout << "INF";
            }
            else
            {
                cout << m[i][j];
            }
            if (j != v - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
