#include<stdio.h>
#include <stdlib.h>
#define MAX 2000000
#define VMAX 10000

int main(){
    unsigned short *A, *B;
    int C[VMAX+1],n,i,j;

    scanf("%d",&n);

    A=malloc(sizeof(short)*n+1);
    B=malloc(sizeof(short)*n+1);

    for(i=0;i<=VMAX;i++){
        C[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%hu",&A[i+1]);
        C[A[i+1]]++;
    }
    for(i=1;i<VMAX;i++){
        C[i]=C[i]+C[i-1];
    }
    for(i=1;i<=n;i++){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }
    for(i=1;i<=n-1;i++){
        printf("%d ",B[i]);
    }
    printf("%d\n",B[n]);
    return 0;
}
