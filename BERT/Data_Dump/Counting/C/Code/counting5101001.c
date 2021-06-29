#include <stdio.h>
#include <stdlib.h>

#define N 2000001
#define MAXA 10000

int *A, *B;

void countingSort(int);

int main() {
    int i, numA;
    
    scanf("%d", &numA);

    A = malloc(sizeof(int) * numA + 1);
    B = malloc(sizeof(int) * numA + 1);

    for(i = 0; i < numA; i++) scanf("%d", &A[i+1]);

    countingSort(numA);

    for(i = 1; i <= numA; i++){
        if(i > 1)printf(" ");
        printf("%d", B[i]);
    }

    printf("\n");

    return 0;
}

void countingSort(int numA){
    int i, C[MAXA];

    for(i = 0; i <= MAXA; i++) C[i] = 0;

    for(i = 0; i < numA; i++) C[A[i+1]]++;
    

    for(i = 1; i <= MAXA; i++) C[i] = C[i] + C[i-1];

    for(i = 1; i <= numA; i++){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}
