#include <stdio.h>
#define N 100
int main(){
  int i,j,k=0,n,F,min;
  int A[N];

    scanf("%d",&n);

  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }

  for(i=0 ; i<n ; i++){
    min=i;
    for(j=i ; j<n ; j++){
      if(A[j] < A[min]){
	min=j;
      }
    }
    if(A[i]!=A[min]){
    F=A[i];
    A[i]=A[min];
    A[min]=F;
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
