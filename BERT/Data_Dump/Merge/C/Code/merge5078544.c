#include <stdio.h>

#define INFTY 1000000001

void merge(int, int, int);
void mergeSort(int, int);

int A[500002], c=0;

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    mergeSort(0, n);
    for(i=0; i<n-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n%d\n",A[n-1], c);
    return 0;
}

void merge(int left, int mid, int right){
    int n1, n2, L[250001], R[250001], i, j, k;
    n1=mid-left;
    n2=right-mid;
    for(i=0; i<n1; i++){
        L[i]=A[left+i];
    }
    for(i=0; i<n2; i++){
        R[i]=A[mid+i];
    }
    L[n1]=INFTY;
    R[n2]=INFTY;
    i=0;
    j=0;
    for(k=left; k<right; k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right){
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
        c+=right-left;
    }
}
