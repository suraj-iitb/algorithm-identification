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
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    int c[10001] = {};

    rep(i, n)
    {
        cin >> a[i + 1];
        c[a[i + 1]]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        c[i] += c[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    for (int i = 1; i <= n; i++)
        i != n ? cout << b[i] << " " : OP(b[i]);

    return 0;
}
