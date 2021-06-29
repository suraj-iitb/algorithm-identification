#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[p]) p = j;
        }
        if (i != p) {
            swap(a[i], a[p]);
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? ' ' : '\n');
    cout << cnt << endl;
}
