#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]), cnt++;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? "" : " ");
    cout << endl << cnt << endl;

    return 0;
}

