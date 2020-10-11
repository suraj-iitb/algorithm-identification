#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10001

int main(){
  int i,j,n=0;
  unsigned short *A,*B;
  int C[VMAX];
  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for ( i = 0; i <= VMAX-1; i++ ) C[i] = 0;
  
  for(i=1;i<=n;i++){
      scanf("%d",&A[i]);
      C[A[i]]++;
  }
  
  for(i=1;i<=VMAX-1;i++){
      C[i]=C[i]+C[i-1];
  }

  for(j=1;j<=n;j++){    
      B[C[A[j]]] = A[j];
      C[A[j]]--;
  }

  for(i=1;i<n+1;i++){
      if(i<n){
        printf("%d ",B[i]);
      }
      else{
        printf("%d\n",B[i]);
      }
    }
  return 0;
}
