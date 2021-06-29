#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

#define NUMMAX 500010

int L[NUMMAX/2], R[NUMMAX/2];
int cnt;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    rep(i, n1) L[i] = A[left+i];
    rep(i, n2) R[i] = A[mid+i];
    L[n1] = INT32_MAX;
    R[n2] = INT32_MAX;
    int i = 0;
    int j = 0;
    rep(n, n1+n2) {
        cnt++;
        if (R[j] < L[i]) {
            A[left+n] = R[j];
            j++;
        } else {
            A[left+n] = L[i];
            i++;
        }
    }
}

void mergeSort(int A[], int left, int right){
    if (left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int s[n];
    rep(i,n) scanf("%d", &s[i]);
    mergeSort(s, 0, n);
    
    rep(i,n) {
        if (i) cout << " ";
        cout << s[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
