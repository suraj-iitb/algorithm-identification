#include <iostream>
#include <algorithm>
using namespace std;

int InsertionSort(int n, int a[]) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int min_j = i;
        bool f = false;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min_j]) {
                min_j = j;
                f = true;
            }
        }
        swap(a[i], a[min_j]);
        if (f) ans++;
    }
    
    return ans;
}

int main() {
    int n, a[110];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = InsertionSort(n, a);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;

    cout << ans << endl;
    return 0;
}
