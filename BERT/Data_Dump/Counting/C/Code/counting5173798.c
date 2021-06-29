#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX 2000000
#define I_MAX 10000

int A[N_MAX], B[N_MAX];

void CountingSort(int, int);

int main(){
  int i, n, q, a_max = 0;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
        if(a_max < A[i]){
          a_max = A[i];
        }
  }
        
  CountingSort(n, a_max);
        
  for(i = 0; i < n; i++){
        if(i > 0){
                printf(" ");
        }
        printf("%d", B[i]);
  }
  printf("\n");
  
  return 0;
}
void CountingSort(int n, int k){
        int i, j;
        int C[I_MAX];

        //printf("%d\n", k);
        
        for(i = 0; i <= k; i++){//initialize
          C[i] = 0;
        }

        for(j = 0; j < n; j++){//build
          C[A[j]]++;
        }
        
        for(i = 1; i <= k; i++){//build2
        C[i] = C[i] + C[i-1];
        }
        
        /*      
  for(i = 0; i <= n; i++){
    printf("%d", C[i]);
        if(i < n){
          printf(" ");
        }else{
          printf("\n");
        }
  } */
        
        for(j = n-1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
        }
        
        /*      
  for(i = 0; i < n; i++){
    printf("%d", A[i]);
        if(i < n-1){
          printf(" ");
        }else{
          printf("\n");
        }
  }*/
}

