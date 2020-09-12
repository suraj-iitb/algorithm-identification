#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, a[110], cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[j + 1]) continue;
            swap(a[j], a[j + 1]);
            cnt++;
        }
    
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
