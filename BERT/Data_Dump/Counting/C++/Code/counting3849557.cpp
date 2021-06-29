#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    cout << a[0];
    for (int i=1; i<n; i++) cout << " " << a[i];
    cout << endl;
}
