#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    vector<int> a(n + 1, 0);
    int maxa = INT_MIN;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        if (a[i] > maxa) {
            maxa = a[i];
        }
    }

    vector<int> c(maxa, 0);
    for (int v = 0; v <= maxa; v++) {
        c[v] = 0;
    }

    for (int i = 1; i <= n; i++) {
        c[a[i]]++;
    }

    // 積分なので一歩前から進む
    for (int v = 1; v <= maxa; v++) {
        c[v] = c[v] + c[v - 1];
    }

    vector<int> b(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    for (int i = 1; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << b[n] << endl;

    return 0;
}

