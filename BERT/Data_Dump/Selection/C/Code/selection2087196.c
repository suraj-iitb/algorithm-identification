#include<stdio.h>
#include<stdlib.h>

void selection_sort(int* A, int N);
void print_array(int* A, int N);
void swap(int* A, int* B);

int main() {
    int n;
    int i;
    int* A;
    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    for ( i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }
    
    selection_sort(A, n);
    
    free(A);
    return 0;
}

void selection_sort(int* A, int N) {
    int i,j;
    int minj;
    int count = 0;
    for ( i = 0; i < N; i++ ) {
        minj = i;
        for ( j = i; j < N; j++ ) {
            if ( A[j] < A[minj] ) {
                minj = j;
            }
        }
        if ( minj != i ) {
            swap(&A[i], &A[minj]);
            count++;
        }
    }
    
    print_array(A, N);
    printf("%d\n", count);
}

void print_array(int* A, int N) {
    int i;
    for ( i = 0; i < N; i++ ) {
        if ( i != N-1 ) {
            printf("%d ", A[i]);
        } else {
            printf("%d", A[i]);
        }
    }
    printf("\n");
}

void swap(int* A, int* B ) {
    int temp = *A;
    *A = *B;
    *B = temp;
}
