#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000


int main(){
   unsigned short *A, *B;
   int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

   A = malloc(sizeof(short)*n+1);
   B = malloc(sizeof(short)*n+1);



  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < VMAX+1; i++){
    C[i] = 0;
  }

  for(i = 0 ;i < n;i++){
    C[A[i]]++;
  }

  for(i = 1; i < VMAX+1; i++){
    C[i] = C[i] + C[i-1];
  }

  for(i = n-1; i >= 0; i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }


  
  for(i = 0; i < n ; i++){
 
    if(i == n-1){
      printf("%d\n",B[i]);
      break;
    }
    printf("%d ",B[i]);
  }

  return 0;
}
