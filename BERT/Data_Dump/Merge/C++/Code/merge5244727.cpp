#include<bits/stdc++.h>
using namespace std;

int gCount = 0;
long int INF = 10000000000;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[260000];
    int R[260000];
    for (int i = 0; i < n1; i++) {
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid+i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
            gCount++;
        }
        else{
            A[k] = R[j];
            j++;
            gCount++;
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

int main () {
    int n, S[500000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    mergeSort(S, 0, n);
    for ( int i = 0; i<n; i++){
        if (i == 0){
            cout << S[i];
        }
        else{
            cout << " " << S[i];
        }
        
        
    }
    cout << endl;
    cout << gCount << endl;
}
