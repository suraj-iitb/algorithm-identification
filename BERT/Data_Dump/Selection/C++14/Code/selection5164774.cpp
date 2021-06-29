#include<stdio.h>
#include<iostream>

void trace(int A[], int N){
    for(int i = 0; i < N; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int selectionSort(int A[], int N){
    int minj = 1;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        if(minj != i){
            std::swap(A[minj], A[i]); 
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int N;
    int A[100];
    std::cin >> N;
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    int cnt = selectionSort(A, N);
    trace(A, N);
    std::cout << cnt << std::endl;
}
