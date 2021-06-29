#include <iostream>

using namespace std;

const int kMaxN = 100;

int bubbleSort(int *a, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    int A[kMaxN];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = bubbleSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i != n - 1) {
            cout << " ";
        }
    }

    cout << endl;
    cout << count << endl;

}


