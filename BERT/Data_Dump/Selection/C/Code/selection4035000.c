#include<stdio.h>

int main(){
  int i,j,minj,n,A[100],t,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++)
      if(A[j]<A[minj])
	minj=j;
    if(minj!=i)cnt++;
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
  }
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],cnt);
  return 0;
}

