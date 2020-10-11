#include<stdio.h>
#define N 100
int main()
{
  int i,j,k=0,count=0,A[N],n;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	k=A[j];
	A[j]=A[j-1];
	A[j-1]=k;
	count++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  return 0;
}
