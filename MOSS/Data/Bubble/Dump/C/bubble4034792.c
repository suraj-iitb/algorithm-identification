#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 1000000007
#define MAXE9 1000000000

int i, j, k, l;

int main(){
    int N=0;
    int swap=0;
    int tmp;
    int A[100];
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for(i=0;i<N-1;i++){
        for(j=N-1;j>i;j--){
            if(A[j] < A[j-1]){
                tmp =A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                swap++;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i<N-1) printf(" ");
    }
    printf("\n");
    printf("%d\n", swap);
}


