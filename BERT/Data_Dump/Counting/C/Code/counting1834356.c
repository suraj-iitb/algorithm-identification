#include <stdio.h>

#define N 2000001
#define M 10000

int  B[N], C[M];

void CountingSort(int A[N], int k, int n);
  
 


int main(){
  
  int i,n, max = 0, A[N];
  scanf("%d", &n);

  for(i = 1 ; i <=n ; i++ ){
    
    scanf("%d", &A[i]);

    if(A[i] > max) max = A[i];
     
  }
  

CountingSort(A, max, n);

 return 0;
}   
  
void CountingSort(int A[N], int k, int n){
  
  int i, j;
  
 
  for(i = 0 ; i <= k ; i++){
    
    C[i] = 0;
  
  }
  
    for(j = 1 ; j <= n ; j++){
      
      C[A[j]] = C[A[j]]+1;
      
    }

  
  
  for(i = 1 ; i <= k ; i++){
    
    C[i] = C[i] + C[i - 1];
  }
  
  for(j = n ; j >= 1 ; j--){
    
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
    
  }
  
  for(i = 1 ; i <= n ; i++){
  printf("%d", B[i]);
  if (i < n)printf(" ");
   }
  printf("\n");
}
 
