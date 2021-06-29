#include<stdio.h>
#include<string.h>

#define NUM 10000
int C[NUM];

#define ELM_NUM 2000000
int A[ELM_NUM];
int B[ELM_NUM];


void CountingSort(int N){
    
    int i, idx;
    
    for (i=0; i < NUM; i++) {
        C[i] = 0;
    }
    
    /* C[i] ??? i ???????????°????¨?????????? */
    for (i=0; i < N; i++) {
        C[A[i]]++;
    }
    
    /* C[i] ??? i ??\????????°???????????°????¨??????????*/
    for (i=1; i < NUM; i++) {
        C[i] = C[i] + C[i-1];
    }
    
    for (i = N-1; i >=0; i--) {
        
        /* A[i]???????´??????????idx?????\??????*/
        idx = C[A[i]] - 1;
        B[idx] = A[i];
        C[A[i]]--;
    }
    
    return;
}

int main( ){
    
    int i,n;
    
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    
    
    CountingSort(n);
    
    for (i=0; i<n; i++) {
        printf("%d", B[i]);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
