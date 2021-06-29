#include <stdio.h>
#include <stdlib.h>

int ref=0,max;
int *A;

int merge(int left,int mid,int right){
    /*sort????????????A[left..mid-1]??¨A[mid..right-1]??????????????±???*/
    int n1 = mid - left, n2 = right - mid;
    int i,j,k;
    int *L,*R;
    L = (int *)calloc(n1+1,sizeof(int));
    R = (int *)calloc(n2+1,sizeof(int));
    for(i=0;i<n1;i++)L[i] = A[left + i];
    for(i=0;i<n2;i++)R[i] = A[mid + i];
    L[n1] = R[n2] = max+1;
    i = j = 0;
    for(k=left;k<right;k++){
        ref++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{ 
            A[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
}

int mergeSort(int left,int right){
    int mid;
    if(left+1 < right){
        mid = (left + right)/2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    A = (int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++)scanf("%d",A+i);
    max = A[0];
    for(i=1;i<n;i++)if(max<A[i])max=A[i];
    mergeSort(0,n);
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n%d\n",ref);
}
