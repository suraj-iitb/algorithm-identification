#include <stdio.h>
#define N 2000001
 
int A[N],B[N],C[N];

main()
{

  
  int i,n,j,k=0;
  
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
   C[A[i]]++;
   
   if(k < A[i]){
      k = A[i];
   }
  }
  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }
  for(j = n-1; j >= 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    if(i!=n){
      printf("%d ",B[i]);
    }
    else {
      
      printf("%d\n",B[i]);
    }
  }
  return 0;
}
