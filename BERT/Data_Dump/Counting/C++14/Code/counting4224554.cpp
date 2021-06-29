#include <iostream>

using namespace std;

int A[2000010];
int B[2000010];
int C[10010];

void countingSort(const int a[], int b[], int n, int k) {
//    for (int i = 0; i <= k; ++i) C[i] = 0;
    for (int j = 0; j < n; ++j) C[a[j]]++;
    for (int i = 1; i <= k; ++i) C[i] = C[i] + C[i - 1];
    for (int j = n - 1; j >= 0; --j) b[--C[a[j]]] = a[j];
}

void outputArray(int a[], int n) {
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
}

int main() {
    int n, mx = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    countingSort(A, B, n, mx);
    outputArray(B, n);
    return 0;
}

