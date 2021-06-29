#include <stdio.h>
#include <stdlib.h>
#define MAX1 2000001
#define MAX2 10000
int main(){
    unsigned short *A,*B;
    int C[MAX2+1];
    int a,b,c;
    scanf("%d",&a);
    A=malloc(sizeof(short)*a+1);
    B=malloc(sizeof(short)*a+1);
    for(b=0;b<=MAX2;b++){
        C[b]=0;
    }
    for(b=0;b<a;b++){
        scanf("%hu",&A[b+1]);
        C[A[b+1]]++;
    }
    for(b=1;b<=MAX2;b++){
        C[b]=C[b]+C[b-1];
    }
    for(c=1;c<=a;c++){
        B[C[A[c]]]=A[c];
        C[A[c]]--;
    }
    for(b=1;b<=a;b++){
        if(b>1) printf(" ");
        printf("%d",B[b]);
        }
        printf("\n");
        return 0;
    }
