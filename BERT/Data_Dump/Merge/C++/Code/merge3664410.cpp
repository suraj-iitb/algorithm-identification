#include <iostream>

using namespace std;

int n, a[500000];
const int INF = 1e9 + 1;
int ans = 0;

void merge(int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;
    int al[n1 + 1], ar[n2 + 1];
    for (int i = 0; i < n1; ++i)
        al[i] = a[l + i];
    for (int i = 0; i < n2; ++i)
        ar[i] = a[m + i];
    al[n1] = INF;
    ar[n2] = INF;
    for (int i = 0, j = 0, k = l; k < r; ++k) {
        ans++;
        if (al[i] <= ar[j])
            a[k] = al[i++];
        else
            a[k] = ar[j++];
    }
}

void mergeSort(int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m, r);
        merge(l, m, r);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    mergeSort(0, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl << ans << endl;

    return 0;
}
