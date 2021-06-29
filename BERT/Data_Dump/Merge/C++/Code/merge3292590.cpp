#include <iostream>
#include <limits.h>
#define NMAX 500000
using namespace std;
int ncomp = 0;
void merge(int *A, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    int L[n1+1], R[n2+1];
    for (int i=0; i<n1; i++) L[i] = A[left+i];
    for (int i=0; i<n2; i++) R[i] = A[mid+i];
    L[n1] = R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k=left; k<right; k++) {
        if ( L[i] <= R[j] ) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        ncomp++;
    }
}
void mergeSort(int *A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main() {
    int n; cin >> n;
    int S[NMAX]; for (int i=0; i<n; i++) cin >> S[i];
    mergeSort(S, 0, n);
    for (int i=0; i<n; i++) {
        cout << S[i];
        if (i == n-1) cout << endl; else cout << ' ';
    }
    cout << ncomp << endl;
}
