#include <bits/stdc++.h>
using namespace std;

int bubbleSort(int a[], int n) {
    int total_swap = 0;
    int swap_;

    do {
        swap_ = 0;

        for (int j = n - 1; j > 0; j--) {
            if (a[j -1] > a[j]) {
                swap(a[j -1], a[j]);
                swap_++;
            }
        }

        total_swap += swap_;
    } while (swap_ > 0);

    return total_swap;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int count = bubbleSort(a, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }

    cout << endl << count << endl;

    return 0;
}
