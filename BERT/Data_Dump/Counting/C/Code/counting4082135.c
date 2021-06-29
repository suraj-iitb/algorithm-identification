#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define V 10000

int main(){

    unsigned short *A,*B;


    int C[V+1],n,i,j;
    
    
    scanf("%d",&n);

    A = malloc(sizeof(short)*n+1);
    B = malloc(sizeof(short)*n+1);

    for( i=0 ; i<=V+1 ; i++ ){
        C[i] = 0;
    }

    for( i=0 ; i<n ; i++ ){
        scanf("%d",&A[i+1]);
        C[A[i+1]]++;
    }

    for( i=1 ; i<V+1 ; i++ ){
        C[i] = C[i] + C[i-1];
    }

    for( j=1 ;j<n+1 ; j++ ){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for( i=1 ; i<n+1 ; i++ ){
        if( i>1 && i<n+1 ) printf(" ");
        printf("%d",B[i]);
    }

    printf("\n");

    return 0;
}




