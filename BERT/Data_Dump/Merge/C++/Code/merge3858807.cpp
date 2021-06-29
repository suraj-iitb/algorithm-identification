#include<stdio.h>
#include<limits>

#define INFTY 2000000000;
int L[500000/2+2];
int R[500000/2+2];
int cnt = 0;

void merge(int* A, int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i=0; i<n1; i++){
        L[i] = A[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] =  INFTY;
    int i=0;
    int j=0;
    for(int k=left; k<right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int* A, int n, int left, int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main(){

    int n;
    scanf("%d", &n);
    int A[500000];
    for(int i=0; i<n; i++) scanf("%d", &A[i]);

    mergeSort(A, n, 0, n);

    for(int i=0; i<n; i++){
        if(i!=n-1) printf("%d ", A[i]);
        else {
            printf("%d\n", A[i]);
            printf("%d\n", cnt);
        }
    }

    return 0;
}

