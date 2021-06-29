#include <stdio.h>
#include<stdlib.h>
#define S_len 500001
#define INFI 1000000001

int comp = 0;
int L[S_len/2+2],R[S_len/2+2];

void merge(int *S, int left, int right, int mid){
    int i,j,k;
    int n1 = mid - left;
    int n2 = right - mid;
    
    for(i=0; i<n1;i++){
        L[i] = S[left + i];
    }
    for(i=0; i<n2; i++){
        R[i] = S[mid + i];
    }

    L[n1] = INFI;
    R[n2] = INFI;
    i=0; j=0;
    for(k=left; k<right; k++){
        comp++;
        if(L[i]<=R[j]){
            S[k] = L[i++];
        }else{
            S[k] = R[j++];
        }
    } 
}

void mergeSort(int *S,int left,int right){
    if(left+1 < right){
        int mid = (left + right)/2;
        mergeSort(S,left,mid);
        mergeSort(S,mid,right);
        merge(S,left,right,mid);
    }
}

int main(){
    int n,i,left,right;
    int S[S_len];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    
    right = n;
    left = 0;
    mergeSort(S,left,right);

    for(i=0;i<n;i++){
        printf("%d",S[i]);
        if(i!=(n-1))printf(" ");
    }
    printf("\n%d\n",comp);
    return 0;
}
