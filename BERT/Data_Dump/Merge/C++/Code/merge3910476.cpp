#include <bits/stdc++.h>
using namespace std;

#define MAX 500000
int cnt;

void merge(int A[],int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1];
    int R[n2+1];
    for(int i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1] = INFINITY;
    R[n2] = INFINITY;

    int i=0;
    int j = 0;

    for (int k = left; k < right;k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
        }
    }
}

void mergesort(int A[], int n,int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergesort(A,n,left,mid);
        mergesort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}
int main(){
    int n;
    cin >> n;
    int A[MAX];
    cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    mergesort(A,n,0,n);
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << A[i];
    } 
    cout << endl;

    cout << cnt << endl;

    return 0;
}
