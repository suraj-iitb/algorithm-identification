#include <iostream>

using namespace std;

int cnt;
int A[500010], tmp[500010];

void margeSort(int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) / 2;
    margeSort(l, m);
    margeSort(m, r);
    int i = 0;
    for (int il = l, ir = m; il < m || ir < r; cnt++)
        if (il < m)
            if (ir < r)
                tmp[i++] = A[il] < A[ir] ? A[il++] : A[ir++];
            else
                tmp[i++] = A[il++];
        else
            tmp[i++] = A[ir++];
    for (int j = 0; j < i; ++j) A[l + j] = tmp[j];
}

void outputArray(int a[], int n) {
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    margeSort(0, n);
    outputArray(A, n);
    cout << cnt << endl;
    return 0;
}

