#include <bits/stdc++.h>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    //L[0...n1], R[0...n2] を生成
    for(int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    int i = 0, j = 0;
    for(int k = left; k < right; k++) {
        cnt++;
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    int A[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    mergeSort(A, 0, n);

    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << A[i];
    }

    cout << endl;
    cout << cnt << endl;

    return 0;
}
