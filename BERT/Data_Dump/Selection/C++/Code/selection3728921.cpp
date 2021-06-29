#include<stdio.h>

void selectionSort(int A[], int N){
    int num = 0;

    for(int i = 0; i < N; i++){
       int minj = i;
       int tmp;
       for(int j = i; j < N; j++){

            if(A[j] < A[minj]){
                minj = j;
            }

        }
            if(minj != i){
                tmp = A[minj];
                A[minj] = A[i];
                A[i] = tmp;
                num++;                
            }
    }

    for(int i = 0; i < N; i++){
        if(i != 0){
            printf(" "); 
        }
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", num);
}

int main(void){
    int n, a[200];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);

    return 0;   
}
