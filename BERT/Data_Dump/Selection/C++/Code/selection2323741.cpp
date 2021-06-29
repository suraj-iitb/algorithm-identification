#include <iostream>
#include <stdio.h>
#include <utility>

#define MAX_N 100

void select_sort(int*,int);

int A[MAX_N+1];
int count_swap = 0;


int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    select_sort(A,n);
    for(int i = 0; i < n; i++){
        if(i<(n-1))printf("%d ",A[i]);
        if(i == (n-1)) printf("%d\n",A[i]);
    }
    printf("%d\n",count_swap);
    
}

void select_sort(int* a,int n){
    for(int i = 0; i < (n-1); i++){
        int a_min = MAX_N;
        int a_min_idx = MAX_N + 1;
        //A[a_min_idx] = MAX_N + 1;
//        printf("A[a_min_idx]'s address %d count_swap's address %d\n",&A[a_min_idx],&count_swap);//why do those two addresses become same?
        for(int j = i+1; j <n; j++){
            if(A[j] < a_min){
                a_min = A[j];
                a_min_idx = j;
            }
        }
        if(A[i] > A[a_min_idx]){
            std::swap(A[i],A[a_min_idx]);
            count_swap++;
        }

    }
}
