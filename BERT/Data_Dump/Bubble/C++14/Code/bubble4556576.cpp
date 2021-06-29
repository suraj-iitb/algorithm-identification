#include <vector>
#include <iostream>
#include <climits>

using namespace std;

const int kSize = 200000;

int cnt = 0;

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j >= i + 1; --j) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                cnt++;
            }
        }
    }
}
int main() {
    int A[kSize];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    BubbleSort(A, n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }

    cout << endl;
    cout << cnt << endl;
}
