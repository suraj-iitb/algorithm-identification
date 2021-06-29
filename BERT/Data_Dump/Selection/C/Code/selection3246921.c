#include <stdio.h>

void selection_sort(int* A, int n);
void print_line(int* A, int n);
void swap(int* a, int* b);

int main(void){
    int N;
    int A[100];
    int i;
    scanf("%d", &N);

    for(i = 0; i < N; ++i){
        scanf("%d", &A[i]);
    }
    selection_sort(A, N);
    return 0;
}

void selection_sort(int* A, int N){
    int i, j;
    int mini;
    int count = 0;
    for(i = 0; i <= N-1; ++i){
        mini = i;
        for(j=i; j <=N-1; ++j){
            if(A[j] < A[mini]) {
                mini = j;
            }
        }
        swap(&A[i], &A[mini]);
        if(i != mini) count++;
    }
    print_line(A, N);
    printf("%d\n", count);
}

void print_line(int *A, int N){
    int i;
    for(i = 0; i < N-1; ++i){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
}

void swap(int* a, int* b){
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}
