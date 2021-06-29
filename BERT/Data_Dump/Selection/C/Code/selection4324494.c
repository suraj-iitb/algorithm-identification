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

int selection_sort(int A[], int N){
    int i, j;
    int cnt = 0;
    int idx_min;
    for(i = 0; i < N; i++){
        idx_min = i;
        for(j = i; j < N; j++){
            if(A[idx_min] > A[j]){
                idx_min = j;
            }
        }
        if(i != idx_min){
            exchange(A, i, idx_min);
            cnt += 1;
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
    cnt = selection_sort(A, N);

    show_array(A, N);
    printf("%d\n", cnt);

    return 0;

}
