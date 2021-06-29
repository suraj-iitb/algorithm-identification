#include <stdio.h>
#include <stdlib.h>
#define N 100
#define A_IN 100

int main(){
  int i,j,flag,A[N],n,tmp,count=0,minj;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
	tmp=A[i];
	A[i]=A[minj];
	A[minj]=tmp;
	if(i!=minj)count++;
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n%d\n",A[i],count);
    else printf("%d ",A[i]);
  }

  return 0;
}

