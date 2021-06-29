#include <stdio.h>
#define SENTINEL 1000000000

void margeSort(int *, int, int);
void marge(int *, int, int, int);

int cnt = 0;

int main(){
    int A[500000];
    int n;
    int i;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    
    margeSort(A, 0, n);
    
    for(i = 0; i < n-1; i++) printf("%d ", A[i]);
    printf("%d\n%d\n", A[i], cnt);
    
    return 0;
}

void marge(int A[], int left, int mid, int right){
    int n1, n2;
    int i, j, k;
    n1 = mid - left;
    n2 = right - mid;
    
    int L[n1+1], R[n2+1];
    
    for(i = 0; i < n1; i++) L[i] = A[left + i];
    for(i = 0; i < n2; i++) R[i] = A[mid + i];
    
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    
    i = 0;
    j = 0;
    
    for(k = left; k < right; k++){
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

void margeSort(int A[], int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        margeSort(A, left, mid);
        margeSort(A, mid, right);
        marge(A, left, mid, right);
    }
}


