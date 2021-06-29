#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? ' ' : '\n');
    cout << cnt << endl;
}
