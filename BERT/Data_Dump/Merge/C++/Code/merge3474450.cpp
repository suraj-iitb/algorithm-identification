#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>

const int MaxFact = pow(10, 9);
int cnt = 0;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for(int i=0; i<n1; i++){
        L[i] = A[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = MaxFact;
    R[n2] = MaxFact;
    int l=0, r=0;
    for(int i=left; i<right; i++){
        cnt++;
        if(L[l] <= R[r]){
            A[i] = L[l];
            l++;
        } else {
            A[i] = R[r];
            r++;
        }
    }
}
void mergesort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    mergesort(A, 0, n);
    int j;
    for(j=0; j<n-1; j++){
        printf("%d ", A[j]);
    }
    printf("%d\n", A[j]);
    cout << cnt << endl;


    return 0;
}
