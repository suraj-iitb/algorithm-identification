#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int n;
    int A[101];
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i; j < n; ++j) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        swap(A[i], A[min_index]);
        if (min_index != i) {
            ans++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << A[i];
        } else {
            cout << ' ' << A[i];
        }
    }

    cout << endl;
    cout << ans << endl;
}

