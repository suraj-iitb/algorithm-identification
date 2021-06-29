#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;


void trace(int A[], int N){
    for (int i=0; i<N; i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int BubbleSort(int A[], int N){
    int iter, j, i, v;
    int cnt = 0;
    for(iter=0; iter<N-1; iter++){
        for(i=N-1; i>iter; i--){
            j = i - 1;
            if(A[j] > A[i]){
                v = A[j];
                A[j] = A[i];
                A[i] = v;
                cnt++;
            }
        }

    }
    return cnt;
}

int main(){
    int N;
    int A[100];
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    
    int cnt = BubbleSort(A, N);
    trace(A, N);
    printf("%d", cnt);
    printf("\n");
    return 0;
}
