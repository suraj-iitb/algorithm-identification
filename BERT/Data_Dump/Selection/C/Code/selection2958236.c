#include <stdio.h>

int main(){
  int i,n,A[100],j,minj,count=0,tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj])
	minj=j;
    }
    if(minj!=i){
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    count++;
    }
  }
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],count);

  return 0;
}

