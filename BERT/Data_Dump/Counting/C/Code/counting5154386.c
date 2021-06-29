#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define MMAX 10000

int main(){
    unsigned short *A,*B;
    int X[MMAX+1], a;
    scanf("%d",&a);
    A = malloc(sizeof(short)*a+1);
    B = malloc(sizeof(short)*a+1);
    
    for(int i=0;i<=MMAX;i++)X[i]=0;
    for(int i=0;i<a;i++){
        scanf("%hu",&A[i+1]);
        X[A[i+1]]++;
    }
    for(int i=1;i<=MMAX;i++)X[i]=X[i]+X[i-1];
    for(int j=1;j<=a;j++){
        B[X[A[j]]] = A[j];
        X[A[j]]--;
    }
    for(int i=1;i<=a;i++){
        if(i>1)printf(" ");
        printf("%d",B[i]);
        
    }
    printf("\n");
    return 0;
}

