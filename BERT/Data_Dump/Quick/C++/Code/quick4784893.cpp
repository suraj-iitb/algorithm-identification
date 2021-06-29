#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    //L[0...n1], R[0...n2] を生成
    for(int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1].value = SENTINEL;
    R[n2].value = SENTINEL;

    int i = 0, j = 0;
    for(int k = left; k < right; k++) {
        if(L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(struct Card A[], int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(struct Card A[], int p, int r) {
    struct Card t, x;
    x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(A[j].value <= x.value) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;

    return i + 1;
}

void quicksort(struct Card A[], int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

void trace(struct Card A[], int N) {
    for(int i = 0; i < N; i++) {
        cout << A[i].suit << " " << A[i].value << endl;
    }
}

bool isStable(struct Card A[], struct Card B[], int N) {
    for(int i = 0; i < N; i++) {
        if(A[i].suit != B[i].suit) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    struct Card A[n], B[n];

    for(int i = 0; i < n; i++) {
        cin >> A[i].suit >> A[i].value;
        B[i] = A[i];
    }

    mergeSort(A, 0, n);
    quicksort(B, 0, n-1);

    if(isStable(A, B, n)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    trace(B, n);

    return 0;
}
