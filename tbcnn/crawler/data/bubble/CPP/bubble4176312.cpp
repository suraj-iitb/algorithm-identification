#include <iostream>
#include <algorithm>
using namespace std;

int BubbleSort(int n, int a[]) {
    bool f = true;
    int ans = 0;
    while (f) {
        f = false;
        for (int i = n - 1; i > 0; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                f = true;
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    int n, a[110];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = BubbleSort(n, a);

    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;

    cout << ans << endl;
    return 0;
}
