#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 200001
#define MAX 10000
#define rad M_PI/3

int main()
{
    unsigned short *A,*B;
    int X[MAX+1],m,i,j;

    scanf("%d",&m);

    A=malloc(sizeof(short)*m+1);
    B=malloc(sizeof(short)*m+1);

    for (i = 0; i <= MAX; i++) {  X[i]=0;}
    for(i=0;i<m;i++){
        scanf("%hu",&A[i+1]);
        X[A[i+1]]++;
    }
    for(i=1;i<=MAX;i++){X[i]=X[i]+X[i-1];}
    for(j=1;j<=m;j++){
        B[X[A[j]]]=A[j];
        X[A[j]]--;
    }
    for(i=1;i<=m;i++){
        if(i>1)printf(" ");
        printf("%d",B[i]);
    }

    printf("\n");
  return 0;
}

