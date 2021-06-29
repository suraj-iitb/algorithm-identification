#include<stdio.h>
#define N 2000001
#define M 10001

int main(){
  short A[N], B[N];
  int C[M], n;
      int i, k = 0;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    if(A[i] > k) k = A[i];
  }
  
  for(i = 0; i <= k; i++){
    C[i] = 0;
  }

  for(i = 1; i <= n; i++){
    C[A[i]]++;
  }

  for(i = 1; i <= k; i++){
    C[i] += C[i - 1];
  }
  
  
    for(i = n; i > 0; i--){ 
    B[C[A[i]]] = A[i];
    C[A[i]] = C[A[i]]-1;
  }
    
    for(i=1; i <= n ;i++){
      if(i > 1){
	printf(" ");
      }
      printf("%d",B[i]);
    }
    printf("\n");

    return 0;
}
