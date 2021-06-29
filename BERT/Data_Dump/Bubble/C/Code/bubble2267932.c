#include <stdio.h>

#define N 100

int main(){

  int i,j,A[N],n,tmp,count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	count++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }

  printf("%d\n",count);

  return 0;
}
