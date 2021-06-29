#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define INF 1e9 + 1;
using namespace std;

int cnt;

void merge(int* a, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1];
    int R[n2 + 1];
    rep(i, n1) L[i] = a[left  + i];
    rep(i, n2) R[i] = a[mid + i];
    L[n1] = INF; R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k += 1) {
        if (L[i] <= R[j])
             a[k] = L[i++];
        else a[k] = R[j++];
        cnt++;
    }
}

void mergeSort(int* a, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main() {
    cnt = 0;
    int n;
    scanf("%d", &n);
    int a[n];
    rep(i, n) scanf("%d", &a[i]);

    mergeSort(a, 0, n);
    rep(i, n) {
        if (i == n - 1) printf("%d\n", a[i]);
        else printf("%d ", a[i]);
    }
    printf("%d\n", cnt);
}
