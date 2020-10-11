#include <stdio.h>
#include <stdlib.h>
int n;
int *C;
int countingsort(int *A,int *B,int *C,int k){
  int i,j;
  for(i=0;i<=k;i++)C[i]=0;
  for(j=1;j<=n;j++)C[A[j]]++;
  // for(j=1;j<n;j++)printf("%d ",C[j]);
  // printf("%d\n",C[j]);
  for(i=1;i<=k;i++)C[i]=C[i]+C[i-1];
  // for(j=1;j<n;j++)printf("%d ",C[j]);
  // printf("%d\n",C[j]);
   for(j=n;j>=1;j--){
     B[C[A[j]]]=A[j];
     C[A[j]]--;	 
   }
   return 0;
}
int main(){
  int i;
  int k=0;
  int *A,*B;
  
  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n+1);
  B=(int *)malloc(sizeof(int)*n+1);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }
  C=(int *)malloc(sizeof(int)*k);
  //printf("%d\n",k);
  countingsort(A,B,C,k);
  for(i=1;i<n;i++)printf("%d ",B[i]);
  printf("%d\n",B[i]);
  return 0;
}
