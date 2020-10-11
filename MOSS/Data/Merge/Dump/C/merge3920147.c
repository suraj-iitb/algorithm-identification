#include <stdio.h>

int num=0;

void merge(int A[], int n, int left, int mid, int right){
    int n1=mid-left;
    int n2=right-mid;
    int i, j, k;
    int L[250001], R[250001];
    
    for(i=0; i<n1; i++) L[i]=A[left+i];
    for(i=0; i<n2; i++) R[i]=A[mid+i];
    
    L[n1]=1000000000;
    R[n2]=1000000000;
    
    i=j=0;
    for(k=left; k<right; k++){
        num++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}


int main() {

    int A[500000];
    int n, i;
    
    scanf("%d\n", &n);
    for(i=0; i<n; i++) scanf("%d\n", &A[i]);
    
    mergeSort(A, n, 0, n);
    
    for(i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    
    printf("%d\n", num);
    
    return 0;
}

