#include <stdio.h>
#define N 100
int main(){

  int i,j,k=0,F,n;
  int A[N];

  scanf("%d",&n);

  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }

  for(j=1 ; j<n ; j++){
    if(A[j]<A[j-1]){
      F=A[j];
      A[j]=A[j-1];
      A[j-1]=F;
      j=0;
      k++;
    }
  }

  for(i=0 ; i<n-1 ; i++){
    printf("%d ",A[i]);
  }
 printf("%d",A[n-1]);
  printf("\n%d\n",k);

  return 0;
}
