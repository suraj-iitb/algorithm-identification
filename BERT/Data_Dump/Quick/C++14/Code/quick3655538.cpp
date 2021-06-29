#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100010
#define INF 1000000010

struct Card {
    char suit;
    int value;
};

void merge(struct Card A[], int left, int mid, int right) {
    int n_left = mid - left;
    int n_right = right - mid;

    struct Card L[N_MAX / 2 + 2], R[N_MAX / 2 + 2];
    for (int i = 0; i < n_left; i++) {
        L[i] = A[left + i];
    }
    L[n_left].value = INF;

    for (int i = 0; i < n_right; i++) {
        R[i] = A[mid + i];
    }
    R[n_right].value = INF;

    int idx_L = 0;
    int idx_R = 0;
    for (int k = left; k < right; k++) {
        if (L[idx_L].value <= R[idx_R].value) {
            A[k] = L[idx_L];
            idx_L++;
        }
        else {
            A[k] = R[idx_R];
            idx_R++;
        }
    }
}

void mergeSort(struct Card A[], int left, int right) {
    if (right - left > 1) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}


int partition(struct Card A[], int p, int r) {
    struct Card x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            struct Card temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    A[r] = A[i+1];
    A[i+1] = x;
    return i + 1;
}

void quickSort(struct Card A[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q, r);
    }
}

int main() {
    int n;
    cin >> n;
    struct Card QS[N_MAX];
    for (int i = 0; i < n; i++) {
        cin >> QS[i].suit >> QS[i].value;
    }
    struct Card MS[N_MAX];
    for (int i = 0; i < n; i++) {
        MS[i] = QS[i];
    }

    quickSort(QS, 0, n - 1);

    mergeSort(MS, 0, n);
    // for (int i = 0; i < n; i++) {
    //     cout << MS[i].suit << " " << MS[i].value << endl;
    // }
    // cout << endl;

    int is_stable = 1;
    for (int i = 0; i < n; i++) {
        if (QS[i].suit != MS[i].suit) {
            is_stable = 0;
        }
    }

    if (is_stable == 1) {
        cout << "Stable" << endl;
    }
    else {
        cout << "Not stable" << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << QS[i].suit << " " << QS[i].value << endl;
    }
}

