#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int* A, int N);
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
    
    bubble_sort(A, n);
    
    free(A);
    return 0;
}

void bubble_sort(int* A, int N ) {
    char flag = 1;
    int j;
    int count = 0;
    while ( flag ) {
        flag = 0;
        for ( j = N-1; j >= 1; j-- ) {
            if ( A[j] < A[j-1] ) {
                swap(&A[j], &A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    
    print_array(A,N);
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
