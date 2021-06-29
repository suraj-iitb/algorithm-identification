#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void Merge(vector<int> &A, int n, int left, int mid, int right, vector<int> &R, vector<int> &L){
    int SENTINEL = 2000000000;
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)    L[i] = A[left + i];
    for (int i = 0; i < n2; i++)    R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++){
        cnt++;
        if (L[i] <= R[j])   A[k] = L[i++];
        else    A[k] = R[j++];
    }
    return;
}

void mergeSort(vector<int> &A, int n, int left, int right, vector<int> &R, vector<int> &L){
    if (left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid, L, R);
        mergeSort(A, n, mid, right, L, R);
        Merge(A, n, left, mid, right, L, R);
    }
    return;
}

int main(void){
    int MAX = 500000;
    vector<int> A(MAX), L(MAX/2+2), R(MAX/2+2);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    mergeSort(A, n, 0, n, L, R);
    for (int i = 0; i < n; i++){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

