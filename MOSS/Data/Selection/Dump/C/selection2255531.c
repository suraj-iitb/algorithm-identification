#include <stdio.h>
#define N 100

int main(){
  int i,j,minj,A[N],n,stac,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj])minj=j;
    }
    if(i!=minj)count++;
    stac=A[i];
    A[i]=A[minj];
    A[minj]=stac;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],count);
  return 0;
}
