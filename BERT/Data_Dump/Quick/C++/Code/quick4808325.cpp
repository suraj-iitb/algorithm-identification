#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const int INF = 2000000000;

struct Card {
    char suit;
    int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card A[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for( int i = 0; i < n1; i++ ) L[i] = A[left+i];
    for( int i = 0; i < n2; i++ ) R[i] = A[mid+i];
    L[n1].value = R[n2].value = INF;
    int i = 0, j = 0;
    for( int k = left; k < right; k++ ) {
        if(L[i].value <= R[j].value) A[k] = L[i++];
        else A[k] = R[j++];
    }
}

void merge_sort(struct Card A[], int n, int left, int right) {
    if( !(left+1 < right) ) return;
    int mid = (left + right) / 2;
    merge_sort(A, n, left, mid);
    merge_sort(A, n, mid, right);
    merge(A, n, left, mid, right);
}

int partition(struct Card A[], int n, int p, int r) {
    int i, j;
    struct Card x, t;
    x = A[r];
    i = p - 1;
    for( j = p; j < r; j++ ) {
        if( A[j].value <= x.value ) {
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }
    t = A[i+1]; A[i + 1] = A[r]; A[r] = t;
    return i + 1;
}

void quick_sort(struct Card A[], int n, int p, int r) {
    if( !(p < r) ) return;
    int q = partition(A, n, p, r);
    quick_sort(A, n, p, q - 1);
    quick_sort(A, n, q + 1, r);
}

signed main() {
    int n, i, v; cin >> n;
    struct Card A[MAX], B[MAX];
    char S[10];
    for(int i = 0; i < n; i++) {
        scanf("%s %d", S, &v);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }
    merge_sort(A, n, 0, n);
    quick_sort(B, n, 0, n-1);

    bool flg = true;
    for(int k = 0; k < n; k++) {
        if( A[k].suit != B[k].suit ) flg = false;
    }

    if(flg) printf("Stable\n");
    else printf("Not stable\n");
    for(int k = 0; k < n; k++) {
        printf("%c %d\n", B[k].suit, A[k].value);
    }

    return 0;
}

