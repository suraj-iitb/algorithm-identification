/*
#include<iostream>
#include<utility>
using namespace std;
#define INF 1999999999

pair<char, int> P[1000005];
pair<char, int> S[1000005], L[500005], R[500005];
long long sum=0;

void merge(int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i=0; i<n1; i++) {
        L[i] = S[left + i];
    }
    for (int i=0; i<n2; i++) {
        R[i] = S[mid + i];
    }
    L[n1].second = INF;
    R[n2].second = INF;
    int i = 0, j = 0;
    for (int k=left; k<right; k++) {
        if (L[i].second <= R[j].second) {
            S[k] = L[i];
            i++;
        }
        else {
            S[k] = R[j];
            j++;
        }
        sum++;
    }
}

void mergeSort(int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
    return;
}

int partition(int p, int r) {
    int x, i, j;
    pair<char, int> t;
    x = P[r].second;
    i = p - 1;
    for (j = p; j < r; j++) {
        if (P[j].second <= x) {
            i++;
            t = P[i]; P[i] = P[j]; P[j] = t;
        }
    }
    t = P[i + 1]; P[i + 1] = P[r]; P[r] = t;
    return i + 1;
}

void quickSort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> P[i].first >> P[i].second;
        S[i].first = P[i].first;
        S[i].second = P[i].second;
    }
    quickSort(0, n-1);
    mergeSort(0, n);
    for (int i=0; i<n; i++) {
        if (P[i].first != S[i].first) {
            cout << "Not stable\n";
            break;
        }
        if (i == n - 1) cout << "Stable\n";
    }
    for (int i=0; i<n; i++) {
        cout << P[i].first << " " << P[i].second << endl;
    }
    return 0;
}
*/

#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int n, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; i++) L[i] = A[left + i];
    for (i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for (k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(struct Card A[], int n, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(struct Card A[], int n, int p, int r) {
    int i, j;
    struct Card t, x;
    x = A[r];
    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }
    t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;
    return i + 1;
}

void quickSort(struct Card A[], int n, int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, n, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, q + 1, r);
    }
}

int main() {
    int n, i, v;
    struct Card A[MAX], B[MAX];
    char S[10];
    int stable = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s %d", S, &v);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n - 1);

    for (i = 0; i < n; i++) {
        // マージソートとクイックソートの結果を比べる
        if (A[i].suit != B[i].suit) stable = 0;
    }

    if (stable == 1) printf("Stable\n");
    else printf("Not stable\n");
    for (i = 0; i < n; i++) {
        printf("%c %d\n", B[i].suit, B[i].value);
    }
    return 0;
}
