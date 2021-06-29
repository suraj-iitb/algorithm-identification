#include <iostream>
using namespace std;

typedef struct Card {
    int num;
    char c;
} Card;

// MergeSort as stable sort
static const int MAX = 100005;
static const int INFTY = 2000000000;
Card L[MAX / 2], R[MAX / 2];
void merge(Card A[], int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].num = INFTY;
    R[n2].num = INFTY;
    int i = 0, j = 0; // i for left, j for right
    for (int k = left; k < right; k++) {
        if (L[i].num <= R[j].num) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(Card A[], int left, int right) {
    int mid = (right + left) / 2;
    if (left + 1 < right) {
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

// Partition
void swap(Card &a, Card &b) {
    Card tmp = a;
    a = b;
    b = tmp;
}
int partition(Card A[], int p, int r) {
    int x = A[r].num;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].num <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i + 1;
}

// QuickSort
void quickSort(Card A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q, r);
    }
}

// Stable
int isStable(Card dec1[], Card dec2[], int n) {
    for (int i = 0; i < n; i++) {
        if (dec1[i].c != dec2[i].c) return 0;
    }
    return 1;
}


int main() {
    Card dec1[MAX];
    Card dec2[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dec1[i].c >> dec1[i].num;
        dec2[i] = dec1[i];
    }
    mergeSort(dec1, 0, n);
    quickSort(dec2, 0, n-1);

    if (isStable(dec1, dec2, n)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for (int i = 0; i < n; i++) {
        cout << dec2[i].c << " " << dec2[i].num << endl;
    }
    return 0;
}
