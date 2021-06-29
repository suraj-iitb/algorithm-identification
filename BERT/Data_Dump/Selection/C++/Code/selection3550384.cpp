#include <iostream>

using namespace std;

int main() {
    int n, a[100], ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0, minj; i < n; ++i) {
        minj = i;
        for (int j = i; j < n; ++j) {
            if (a[minj] > a[j]) {
                minj = j;
            }
        }
        if (i != minj)
            ans++;
        swap(a[i], a[minj]);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl << ans << endl;

    return 0;
}
