#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1ll << 62) - 1;

ll d[110][110];
int V;

bool warshal_floyd()
{
    int i, j, k;
    rep(k, 0, V)
    {
        rep(i, 0, V)
        {
            rep(j, 0, V)
            {
                if (d[i][k] != INF && d[k][j] != INF)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    rep(i, 0, V)
    {
        if (d[i][i] < 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int E;
    int i, j;
    int x, y, z;

    cin >> V >> E;

    rep(i, 0, V)
    {
        rep(j, 0, V)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = INF;
            }
        }
    }

    rep(i, 0, E)
    {
        cin >> x >> y >> z;
        d[x][y] = z;
    }

    if (warshal_floyd())
    {
        rep(i, 0, V)
        {
            rep(j, 0, V)
            {
                if (d[i][j] == INF)
                {
                    printf("INF");
                }
                else
                {
                    printf("%lld", d[i][j]);
                }

                if (j < V - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        cout << "NEGATIVE CYCLE" << endl;
    }
}
