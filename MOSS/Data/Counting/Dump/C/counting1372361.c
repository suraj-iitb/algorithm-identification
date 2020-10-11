#include <stdio.h>
#include <stdlib.h>
#define NMAX 2000001
#define AMAX 10000
int main(){

  unsigned short *A,*B;

  int i,j,n;
  int C[AMAX+1];

  scanf("%d",&n);


  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }




  for(i=0;i<=AMAX;i++){
    C[i]=0;
  }

  for(j=0;j<n;j++){
    C[A[j+1]]++;
  }

  for(i=1;i<=AMAX;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }




  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
  
  return 0;
  
}
