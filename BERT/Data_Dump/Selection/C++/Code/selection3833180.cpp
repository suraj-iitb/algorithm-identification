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
    int a[n];
    rep(i, n) cin >> a[i];
    int cnt = 0;

    rep(i, n - 1)
    {
        int minv = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minv])
                minv = j;
        }
        if (minv != i)
        {
            swap(a[minv], a[i]);
            cnt++;
        }
    }

    rep(i, n) i != n - 1 ? cout << a[i] << " " : OP(a[i]);
    OP(cnt);

    return 0;
}
