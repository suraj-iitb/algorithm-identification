#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// #define DEBUG

const int INTMAX = 2 * 1e9 + 10;

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, m, s, t, d, p;
    cin >> n >> m;
    ll a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INTMAX;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> d;
        a[s][t] = d;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][k] != INTMAX && a[k][j] != INTMAX)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }

    p = 0;
    for (int k = 0; k < n; k++)
    {
        if (a[k][k] < 0)
            p = 1;
    }

    if (p == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == INTMAX)
                    cout << "INF";
                else
                    cout << a[i][j];
                if (j != n - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }
    else cout << "NEGATIVE CYCLE" << endl;

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)
