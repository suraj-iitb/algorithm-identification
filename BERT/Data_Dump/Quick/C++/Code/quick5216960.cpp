#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

struct Card {
    char suit;
    int value;
};

int MAX = 50002;
int SENTINEL = 2000000000;
vector<Card> L(MAX), R(MAX);

void merge(vector<Card> &A, int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].value = R[n2].value = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(vector<Card> &A, int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(vector<Card> &B, int n, int p, int r) {
    int i, j;
    Card x;
    x = B[r];
    i = p - 1;
    for (int j = p; j < r; j++) {
        if (B[j].value <= x.value) {
            i++;
            swap(B[i], B[j]);
        }
    }
    swap(B[i + 1], B[r]);
    return i + 1;
}

void quickSort(vector<Card> &B, int n, int p, int r) {
    int q;
    if (p < r) {
        int q = partition(B, n, p, r);
        quickSort(B, n, p, q - 1);
        quickSort(B, n, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Card> A(n);
    vector<Card> B(n);
    for (int i = 0; i < n; i++) {
        Card c;
        cin >> c.suit >> c.value;
        A[i] = B[i] = c;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n - 1);

    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) {
            stable = false;
        }
    }

    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i ++) {
        cout << B[i].suit << " " << B[i].value << endl;
    }

    return 0;
}


