#include <iostream>
using namespace std;

int main() {
    int n, tmp, a[100], count, minIdx;

    // Input
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    count = 0;

    // Sort
    for (int i=0; i<n; i++) {
        minIdx = i;
        for(int j=i; j<=n-1; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        // Swap
        if (a[i] != a[minIdx]) {
            tmp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = tmp;
            count++;
        }
    }

    // Output
    for (int i=0; i<n; i++) {
        cout << a[i];
        if (i==n-1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
    cout << count << endl;

    return 0;
}
