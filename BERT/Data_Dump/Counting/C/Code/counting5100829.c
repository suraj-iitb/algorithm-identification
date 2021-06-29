#include <stdio.h>
#include <stdlib.h>

#define N 2000001
#define MAX 10000

int C[MAX],n;

void CountingSort(short *,short *,int);

int main(){
    unsigned short *A,*B;
    int i,k=MAX;

    scanf("%d",&n);

    A=malloc(sizeof(short)*n+1);
    B=malloc(sizeof(short)*n+1);

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    CountingSort(A,B,k);
    for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[i]);

    free(A);
    free(B);

    return 0;
}

void CountingSort(short A[],short B[],int k){
    int i,j;
    for(i=0;i<k;i++) C[i]=0;

    for(j=0;j<n;j++) C[A[j]]++;

    for(i=1;i<k;i++) C[i]+=C[i-1];

    for(j=n-1;j>=0;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]=C[A[j]]-1;
    }
    for(i=0;i<n;i++)A[i]=B[i+1];
}
