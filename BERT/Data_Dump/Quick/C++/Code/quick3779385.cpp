#include <iostream>
#include <vector>
using namespace std;

static const int INF = 1000000000;

struct Card {
    char suit;
    int value;
};

void merge(vector<Card> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<Card> L(n1 + 1), R(n2 + 1);
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].value = INF, R[n2].value = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void merge_sort(vector<Card> &A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left , mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(vector<Card> &A, int p, int r) {
    Card x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void quick_sort(vector<Card> &A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Card> A(n), B(n);
    for (int i = 0; i < n; i++) {
        char s;
        int x;
        cin >> s >> x;
        A[i].suit = s, A[i].value = x;
        B[i].suit = s, B[i].value = x;
    }

    merge_sort(A, 0, n);
    quick_sort(B, 0, n - 1);

    bool is_stable = true;
    for (int i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) {
            is_stable = false;
            break;
        }
    }

    if (is_stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << B[i].suit << " " << B[i].value << endl;
    }
    return 0;
}
