#include<stdio.h>
#define N 100
int main()
{
  int i,j,m,k=0,n,A[N],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    m=i;
    for(j=i;j<n;j++){
      if(A[j]<A[m]){
	m=j;
      }
    }
    k=A[i];
    A[i]=A[m];
    A[m]=k;
    if(i!=m)count++;
  }
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}
