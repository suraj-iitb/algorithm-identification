#include <iostream>
using namespace std;

int INFTY = 1000000000, cnt = 0;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; ++i) L[i] = A[left + i];
    for (int i = 0; i < n2; ++i) R[i] = A[mid + i];
    L[n1] = INFTY; R[n2] = INFTY;
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
            ++cnt;
        }
        else {
            A[k] = R[j];
            ++j;
            ++cnt;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n, S[500010];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> S[i];

    mergeSort(S, 0, n);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << S[i];
    }
    cout << endl << cnt << endl;
    
    return 0;
}
