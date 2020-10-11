#include <stdio.h>
#define N 100

int main(){
  int temp,i,j,n,A[N],count=0;

  scanf("%d",&n);

  for(i=0;i < n;i++)
    scanf("%d",&A[i]);

  for(i=0;i< n;i++){
    for(j = n-1;j > i;j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}

