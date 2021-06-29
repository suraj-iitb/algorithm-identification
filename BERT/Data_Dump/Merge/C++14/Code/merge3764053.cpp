#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;

int L[500001], R[500001];
int cnt = 0;

void merge(int *A, int left, int mid, int right){
    int i;
    int n = mid - left + 1;
    int n2 = right - mid;
    for(i=0;i<n;i++) L[i] = A[left+i];
    for(i=0;i<n2;i++) R[i] = A[mid+i+1];
    L[n] = R[n2] = INT_MAX;
    int r=0, l=0;
    for(i=left;i<=right;i++){
        cnt++;
        if(L[l] <= R[r]){
            A[i] = L[l++];
        }else{
            A[i] = R[r++];
        }
    }
}

void mergeSort(int *A, int left, int right){
    if(left<right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    rep(i,n){
        cin >> A[i];
    }
    mergeSort(A,0,n-1);
    rep(i,n){
        cout << A[i];
        i==n-1 ? cout << endl : cout << " ";
    }
    cout << cnt << endl;
    return 0;
}
