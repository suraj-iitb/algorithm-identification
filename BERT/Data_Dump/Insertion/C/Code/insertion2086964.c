#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int* A, int N);
void print_array(int* A, int N);

int main() {
    int n;
    int* A;
    int i;
    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    for ( i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }
    
    insertion_sort(A, n);
    
    free(A);
    return 0;
}

void insertion_sort(int* A, int N) {
    int i,j;
    int v;
    for ( i = 1; i < N; i++ ) {
        print_array(A, N);
        
        v = A[i];
        j = i-1;
        while ( j >= 0 && A[j] > v ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    print_array(A, N);
}

void print_array(int* A, int N ) {
    int i;
    for ( i = 0; i < N; i++ ) 
        if ( i != N-1 )printf("%d ", A[i]);
        else printf("%d", A[i]);
    printf("\n");
}
