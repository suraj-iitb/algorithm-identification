#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[2000010], b[2000010];
ll c[10010];

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    
    for (int i = 1; i <= 10000; i++)
        c[i] += c[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}
