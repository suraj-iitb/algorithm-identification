#include <stdio.h>
#include <stdlib.h>
#define VMAX 1000000

int main(){
  unsigned short *A,*B;
  int n,C[VMAX],i,j,k=0;
  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    if(A[i+1]>k)k=A[i+1];
  }

  /*counting sort*/
  
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  
  for(j=0;j<n;j++){
    C[A[j+1]]++;
  }

  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
     
  return 0;
}

