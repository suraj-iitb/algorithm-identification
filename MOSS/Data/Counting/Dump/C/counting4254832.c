#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
    int *A,*B;
    int C[VMAX+1];
    int n,i,j;
    scanf("%d",&n);
    A =(int *)malloc(sizeof(int)*n+1);
    B=(int *)malloc(sizeof(int)* n+1);
    
    for(i=0;i<VMAX+1;i++) C[i]=0;
    for( i=0;i<n;i++){
        scanf("%d",&A[i+1]);
        C[A[i+1]]++;
    }
    for( i=1;i<VMAX+1;i++){
        C[i] +=C[i-1];
    }
    for( j=n;j>0;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
    for( j=1;j<=n;j++){
        if(j != 1)putchar(' ');
        printf("%d",B[j]);
    }
    putchar('\n');
    return 0;
}

