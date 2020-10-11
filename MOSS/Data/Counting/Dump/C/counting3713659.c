#include <stdio.h>
#include <stdlib.h>

void CountingSort(int *A, int *B,int *C, int n, int k){
   for(int i = 0; i < k; i++){
       C[i] = 0;
   }
    for(int j = 0; j < n; j++){
        C[A[j]] = C[A[j]]+1;
   /* C[i] now contains the number of elements equal to i */
    }
    for(int i = 1; i < k; i++){
     C[i] = C[i] + C[i-1];
    /* C[i] now contains the number of elements less than or equal to i */
}
   for(int i = 1; i < k; i++){
   }
    for(int j = n - 1; j >= 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
    }
}   
   
   
int main(int argc, char** argv) {

    int n,max, min = 1000000000;
    scanf("%d",&n);
    int *A = (int*)malloc(n * sizeof(int));
    int *B = (int*)malloc(n * sizeof(int));
    for(int a = 0; a < n; a++){
            scanf("%d",&A[a]);
            if(max<A[a])max=A[a];
            if(min>A[a])min=A[a];
            B[a] = 0;
    }
    int k = 2 + (max - min);
    int *C = (int*)malloc(k * sizeof(int));
    CountingSort(A,B,C,n,k);
    
    for(int a = 1; a < n +1; a ++){
      printf("%d",B[a]);
            if(a < n){
                printf(" ");
            } 
    }

    
    printf("\n");
    return (0);
}
