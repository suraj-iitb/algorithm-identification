#include <stdio.h>

void bubble_sort(int* A, int n);
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
    bubble_sort(A, N);
    return 0;
}

void bubble_sort(int* A, int N){
    int j;
    int flag = 1;
    int count = 0;
    while(flag){
        flag = 0;
        for(j=N-1; j>=1; --j){
            if(A[j] < A[j-1]){
                swap(&A[j], &A[j-1]);
                flag = 1;
                ++count;
            }
        }
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
