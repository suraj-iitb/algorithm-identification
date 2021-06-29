#include <stdio.h>
#include <stdlib.h>
#define VMAX 10000

int main(){
  unsigned short *A,*B;
  int i,j,n;
  int C[VMAX+1];
 
  scanf("%d",&n);
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]); 
  }
  
  for(i=0;i<VMAX;i++){
    C[i] = 0;
  }
  
  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<VMAX;i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<n+1;i++){
    if(i == n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
   }
  return 0;
}

