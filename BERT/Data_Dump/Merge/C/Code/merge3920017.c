#include<stdio.h>

#define N 500000
#define M 2000000000

int cnt=0, L[N/2+2], R[N/2+2];

void merge(int A[], int left, int mid, int right){
    int n1, n2, i, j;
    n1 = mid - left; n2 = right - mid;

    for(i=0 ; i<n1 ; i++)   L[i] = A[left+i];
    for(i=0 ; i<n2 ; i++)   R[i] = A[mid+i];
    
    L[n1] = R[n2] = M;
    i=0; j=0;

    for(int k=left ; k<right ; k++, cnt++){
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

void mergeSort(int A[], int left, int right){
    if(left+1<right){
        int mid = (left+right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main(void){
    int n, S[500000];
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) scanf("%d", &S[i]);
    mergeSort(S, 0, n);
    for(int i=0 ; i<n ; i++)
        if(i==n-1)    printf("%d\n", S[i]);
        else            printf("%d ", S[i]);
    printf("%d\n",cnt);
    return 0;

}

