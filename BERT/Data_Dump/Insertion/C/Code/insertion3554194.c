
#include <stdio.h>

void insertion_sort(int* A, int n);
void print_line(int* A, int n);

int main(void){
    int N;
    int A[100];
    int i;
    scanf("%d", &N);

    for(i = 0; i < N; ++i){
        scanf("%d", &A[i]);
    }
    insertion_sort(A, N);
    return 0;
}

void insertion_sort(int* A, int N){
    int i, j;
    int v;
    print_line(A, N);
    for(i = 1; i <= N-1; ++i){
        v = A[i];
        j =i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print_line(A, N);
    }
}

void print_line(int *A, int N){
    int i;
    for(i = 0; i < N-1; ++i){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
}
