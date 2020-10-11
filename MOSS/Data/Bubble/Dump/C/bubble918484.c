#include <stdio.h>
#define N 100

int main()
{

  int n,k=0,f;
  int A[N];
  int i,j;
  
  
  scanf("%d",&n);

  k = 0;
  for(i = 0; i < n; i++){
    
    scanf("%d",&A[i]);
    
  }
  for(i = 0; i < n; i++){
    for(j = n-1; j >= i+1; j--){
      
      if(A[j] < A[j-1]){
      f = A[j];      
      A[j] = A[j-1]; 
      A[j-1] = f;
      k++;
      }
      
    }
  }
  
  for(i = 0; i < n; i++){
    
    if(i != 0){
      printf(" ");
    }
    
    printf("%d",A[i]);
    
    }
  
  printf("\n");
  printf("%d\n",k);
  
  return 0;
}
