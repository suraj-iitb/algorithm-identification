#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int A[500000];
int cnt;

void merge(int A[], int left, int mid, int right) {
    int L[250001], R[250001];
    int n1 = mid - left;
    int n2 = right - mid;
    
    for (int i = 0; i < n1 + 1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + 1 + i];

    L[n1 + 1] = INFINITY;
    R[n2] = INFINITY;

    int li = 0, rj = 0;
    for (int ak = left; ak < right + 1; ak++ ) {
        cnt++;
        if (L[li] <= R[rj]) {
            A[ak] = L[li];
            li++;
        } else {
            A[ak] = R[rj];
            rj++;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if (left == right) return;

    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}


int main(void) {
    int n;
    cnt = 0;

    cin >> n;
    for (int i = 0; i < n; i++ ) cin >> A[i];

    mergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++ ) {
        if ( i ) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}
