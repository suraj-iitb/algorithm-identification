#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    // insertion sort
    for (int i = 1; i < n; i++) {
        // output
        for (int j = 0; j < n; j++) cout << a[j] << (j < n - 1 ? " " : "");
        cout << endl;
        // sort
        if (a[i] > a[i - 1]) continue;
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--) {
            swap(a[j], a[j - 1]);
        }
    }

    for (int i = 0; i < n; i++) cout << a[i] << (i < n - 1 ? " " : "");
    cout << endl;

    return 0;
}

