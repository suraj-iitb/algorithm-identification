#include <iostream>
#define MAX 500000
using namespace std;

int A[MAX];
int R[MAX / 2 + 2];
int L[MAX / 2 + 2];
int cnt;

void merge(int *A, int left, int mid, int right) {
    int N1 = right - mid;
    int N2 = mid - left;

    for ( int i = 0; i < N1; ++i ) {
        R[i] = A[mid + i];
    }
    for ( int i = 0; i < N2; ++i ) L[i] = A[left + i];

    R[N1] = 1000000000;
    L[N2] = 1000000000;

    int j = 0,k = 0;

    for ( int i = left; i < right; ++i ) {
        cnt++;
        if ( R[j] <= L[k] ) {
            A[i] = R[j++];
        }
        else {
            A[i] = L[k++];
        }
    }
}

void mergeSort(int *A, int left, int right) {
    int mid;
    if ( left + 1 < right ) {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n,i;

    cnt = 0;

    cin >> n;
    for ( i = 0; i < n; ++i ) {cin >> A[i];}


    mergeSort(A, 0, n);

    for ( i = 0; i < n; ++i ) {
        if ( i ) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
