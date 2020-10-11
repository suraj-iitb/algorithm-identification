#include<stdio.h>

void show_array(int A[], int N){
    int i;
    for(i = 0; i < N; i++){
        printf("%d", A[i]);
        if(i < N - 1){
            putchar(' ');
        }
        else{
            putchar('\n');
        }
    }
}

void exchange(int A[], int i, int j){
    int tmp;
    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int bubble_sort(int A[], int N){
    int cnt = 0;
    int i, j;
    for(i = 0; i < N - 1; i++){
        for(j = N - 1; j > i; j--){
            if(A[j] < A[j-1]){
                exchange(A, j, j - 1);
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main(void){
    int N, i, cnt;
    int A[100];

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    cnt = bubble_sort(A, N);

    show_array(A, N);
    printf("%d\n", cnt);

    return 0;
}

