#include <stdio.h>

int main () {
  int i,j,n,v,N;
  
  scanf("%d",&N);

  int A[N];
 

  for(i=0;i<N;i++) {
    scanf("%d",&A[i]);
  }
  for(n=0;n<N;n++) {
    if(n==0) {
      printf("%d",A[n]);
    }
    else{
      printf(" %d",A[n]);
    }
    }
  printf("\n");

  for(i=1;i<N;i++) {
    v = A[i];
    j = i-1;
     
      while(j>=0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
      
      }
      A[j+1] = v;
   for(n=0;n<N;n++) {
     if(n==0) {
       printf("%d",A[n]);
     }
     else{
      printf(" %d",A[n]);
     }
    }
    printf("\n");
  }

  return 0;
}
      

  

  

  
  

