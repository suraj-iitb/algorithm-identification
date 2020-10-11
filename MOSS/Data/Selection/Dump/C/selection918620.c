#include <stdio.h>

#define N 100

int main()
{

  int n,k=0,f;
  int A[N];
  int i,j;
  int mini;
  
  
  scanf("%d",&n);

  k = 0;
  for(i = 0; i < n; i++){
    
    scanf("%d",&A[i]);
    
  }
  for(i = 0; i <= n-1; i++){
    mini = i;
    for(j = i; j <= n-1; j++){
     
      if(A[j] < A[mini]){
	mini = j;
      }
    } 
    
    f = A[i];      
    A[i] = A[mini]; 
    A[mini] = f; 

    if(mini != i){
      k++;
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
