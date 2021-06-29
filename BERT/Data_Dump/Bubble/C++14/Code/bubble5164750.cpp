#include<stdio.h>
#include<algorithm>
#include<iostream>

void trace(int A[], int N){
    for(int i = 0; i < N; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int bubbleSort(int A[], int N){
    bool isSwapped = true;
    int i = 0;
    int cnt = 0;
    while(isSwapped){
        isSwapped = false;
        for(int j = N - 1; j > i; j--){
            if(A[j-1] > A[j]){
                std::swap(A[j-1], A[j]);
                isSwapped = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int N;
    int A[100];
    int cnt;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    cnt = bubbleSort(A, N);
    trace(A, N);
    printf("%d\n",cnt);
}
