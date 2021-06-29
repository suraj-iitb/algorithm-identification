#include<stdio.h>

#define M 2000000

void CountingSort(int, int);

int n, A[M], B[M];

int main(){
    int i, k=0;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(k < A[i]){
            k = A[i];
        }
    }

    CountingSort(n, k);

    for(i=0;i<n;i++){
        if(i < n-1){
            printf("%d ",B[i]);
        }
        else{
            printf("%d\n",B[i]);
        }
    }

    return 0;
}

void CountingSort(int n, int k){
    int C[M], i, j;

    for(i=0;i<=k;i++){
        C[i] = 0;
    }

    for(j=0;j<n;j++){
        C[A[j]]++;
    }

    for(i=1;i<=k;i++){
        C[i] += C[i-1];
    }

    for(j=n-1;j>=0;j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}
