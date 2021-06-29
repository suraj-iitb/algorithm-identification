#include <iostream>

using namespace std;

int A[100];

int BubbleSort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (a[j - 1] <= a[j]) continue;
            swap(a[j - 1], a[j]);
            count++;
        }
    }
    return count;
}

int main() {
    int n, count;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    count = BubbleSort(A, n);
    cout << A[0];
    for (int i = 1; i < n; ++i) cout << ' ' << A[i];
    cout << endl << count << endl;
    return 0;
}

