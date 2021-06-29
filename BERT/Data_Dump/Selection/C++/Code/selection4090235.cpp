#include <stdio.h>
void trace(int A[], int N){
    for (int i = 0; i < N; i++){
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

/* 選択ソート */
int selectionSort(int A[], int N){
    int i, j, min_index, temp, count;
    count = 0;
    for (i = 0; i < N; i++){
        min_index = i;
        for (j = i; j < N; j++){
            if (A[j] < A[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
            count += 1;
        }
    }
    return count;
}

int main() {
    int N, i, count;
    int A[100];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    count = selectionSort(A, N);
    trace(A, N);
    printf("%d\n", count);

    return 0;
}

