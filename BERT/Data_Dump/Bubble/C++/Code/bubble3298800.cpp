#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    int cnt = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (a[j + 1] < a[j]) {
                swap(a[j], a[j + 1]);
                cnt ++;
            }
        }
    }
    rep(i, 0, n) {
        if (i == n - 1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
    cout << cnt << endl;
    return 0;
}

