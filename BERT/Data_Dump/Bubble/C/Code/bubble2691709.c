#include <stdio.h>

/* out function */
void trace(int A[], int N){
    int i;
    for( i = 0; i < N; i++ ){
        if( i > 0) printf(" "); // single space to separate elments
        printf("%d", A[i]);
    }
    printf("\n");
}

/* insert sort (zero origin) */
void BubbleSort(int A[], int N){
    int i, j, v;
    int c = 0; // number of swap operations
    for( i = 0; i < N; i++ ){
        for( j = N -1; j >= (i + 1); j-- ){
            if( A[j] < A[j-1] ){
                v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
                c++; // count up
            }
        }
    }

    /* print sorted sequence */
    trace(A, N); 
    /* print the number of swap operations */
    printf("%d\n",c);
}

/* main function */
int main(){
    int N, i;
    int A[100];

    scanf("%d", &N);
    for( i = 0; i < N; i++) scanf("%d", &A[i]);

    BubbleSort(A, N);

    return 0;    
}
