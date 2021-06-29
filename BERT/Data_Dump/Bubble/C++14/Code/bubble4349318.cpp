#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                ++swaps;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << '\n';
    cout << swaps << endl;
    return 0;
}
