#include <stdio.h>
#include <stdlib.h>

#define A_MAX 10001

void Counting_Sort(int *, int *);
int n;

int main(){
        int *A, *B;
        int i;

        scanf("%d", &n);
        A = malloc(sizeof(int) * n);
        B = malloc(sizeof(int) * n);

        for(i = 0; i < n; i++){
                scanf("%d", &A[i]);
        }

        Counting_Sort(A, B);
        
        for(i = 0; i < n ;i++){
                printf("%d", B[i]);
                if(i + 1 != n)printf(" ");
        }
        printf("\n");

        return 0;
}

void Counting_Sort(int *A, int *B){
        int C[A_MAX];
        int i, j;

        for(i = 0; i <= A_MAX; i++){
                C[i] = 0;
        }

        for(i = 0 ; i < n ; i++){
                C[A[i]]++;
        }

        for(j = 0 ; j <= A_MAX ; j++){
                C[j] = C[j] + C[j - 1];
        }

        for(j = n - 1 ; j >= 0 ; j--){
                B[C[A[j]]-1] = A[j];
                C[A[j]]--;
        }

}
