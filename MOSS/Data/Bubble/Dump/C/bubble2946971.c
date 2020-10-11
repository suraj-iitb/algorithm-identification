#include <stdio.h>
#include <stdlib.h>

#define N 100
#define A_IN 100

int main(){
  int i,j,flag,A[N],n,tmp,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n%d\n",A[i],count);
    else printf("%d ",A[i]);
  }

  return 0;
}

