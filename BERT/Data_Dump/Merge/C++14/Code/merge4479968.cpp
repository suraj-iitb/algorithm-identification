#include <iostream>
using namespace std;

#define N 500001
#define LARGE 1000000001

int n;
int swap_count = 0;
int L[N / 2 + 2], R[N / 2 + 2];


void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    L[n1] = LARGE;
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    R[n2] = LARGE;

    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        swap_count++;
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
    cin >> n;

    int A[N];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    mergeSort(A, 0, n);

    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << swap_count<< endl;
}
