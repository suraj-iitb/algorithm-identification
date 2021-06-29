#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        rep(k, n)
        {
            k != n - 1 ? cout << a[k] << " " : OP(a[k])
        }

        int v = a[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < v)
                break;

            a[j + 1] = a[j];
        }
        a[j + 1] = v;
    }
    rep(k, n)
    {
        k != n - 1 ? cout << a[k] << " " : OP(a[k])
    }
    return 0;
}
