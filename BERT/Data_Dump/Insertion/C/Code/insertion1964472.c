#include <stdio.h>
#define up 1000

void insertionSort(int A[], int N){
    int i = 0;
    int j = 0;
    int v = 0;
    int l = 0;
    int k = 0;
    
    
    for(i = 1; i < N + 1; i++){
        for(l = 0; l < N; l++){
            k = N - 1;
            if(l == k){
                printf("%d\n", A[l]);
             }else{
                printf("%d ", A[l]);
            }
        }
        if(i != 0){
            v = A[i];
            j = i - 1;
            while(j >= 0 && A[j] > v){
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = v;
        }
        
    }

}

int main(void){
    int N = 0;
    int A[up] = {};
    int i = 0;
    
    scanf("%d", &N);
    if(1 > N || 100 < N){
        printf("Error\n");
        scanf("2:%d", &N);
    }

    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    insertionSort(A, N);
    
    return 0;
}
