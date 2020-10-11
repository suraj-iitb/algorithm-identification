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

void insertion_sort(int A[], int N){
    int i, j;
    int val;
    for(i = 1; i < N; i++){
        val = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > val){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = val;

        show_array(A, N);
    }
}

int main(void){
    int A[100];
    int N;
    int i;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    show_array(A, N);
    insertion_sort(A, N);

    return 0;
}


