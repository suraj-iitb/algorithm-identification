#include <stdio.h>

#define N 1000

int main()
{
  int A[N],i,j,k,v,n;

  scanf("%d",&n);
 
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<n-1; i++){
    
    printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");

  for(k=1; k<n; k++){
    
    v = A[k];
    j = k-1;
    
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }    
    for(i=0; i<n-1; i++){
      printf("%d ",A[i]);
    }
    printf("%d",A[n-1]);
    printf("\n");
  }
  return 0;
}

