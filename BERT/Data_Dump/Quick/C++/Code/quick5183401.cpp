#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100000
#define SENTINEL 2000000000

typedef struct Card {
    char suit;
    int value;
} C;

C L[MAX_N / 2 + 2], R[MAX_N / 2 + 2];

void merge(C a[], int n, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; i++)L[i] = a[left + i];
    for (i = 0; i < n2; i++)R[i] = a[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for (k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }
    return;
}

void merge_sort(C a[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(a, n, left, mid);
        merge_sort(a, n, mid, right);
        merge(a, n, left, mid, right);
    }
    return;
}

int partition(C a[], int n, int left, int right) {
    C t, x;
    x = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j].value <= x.value) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}

void quick_sort(C a[], int n, int left, int right) {
    if (left < right) {
        int q = partition(a, n, left, right);
        quick_sort(a, n, left, q - 1);
        quick_sort(a, n, q + 1, right);
    }
    return ;
}


int main() {
    int n, i, v;
    C A[MAX_N], B[MAX_N];
    char s[10];
    int stable = 1;

    cin >> n;

    for (i = 0; i < n; i++) {
      cin>>A[i].suit>>A[i].value;
        B[i]=A[i];
    }
    merge_sort(A, n, 0, n);
    quick_sort(B, n, 0, n - 1);

    for (i = 0; i < n; i++) if (A[i].suit != B[i].suit)stable = 0;


        if (stable == 1)cout << "Stable" << endl;
        else cout << "Not stable" << endl;

    for (i = 0; i < n; i++) {
        cout << B[i].suit << " " << B[i].value << endl;
    }
    return 0;
}

