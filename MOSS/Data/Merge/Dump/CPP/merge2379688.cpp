#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n, a[500010], cnt = 0;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + i];
    L[n1] = R[n2] = INF;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) a[k] = L[i++];
        else a[k] = R[j++];
        cnt++;
    }
}

void mergeSort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
