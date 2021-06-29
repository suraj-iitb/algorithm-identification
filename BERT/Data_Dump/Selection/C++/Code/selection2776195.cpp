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
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[minj]) minj = j;
        }
        if (i - minj) cnt++;
        swap(a[i], a[minj]);
    }

    for (int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? "" : " ");
    cout << endl << cnt << endl;

    return 0;
}

