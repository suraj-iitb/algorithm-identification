#include<stdio.h>
#include<math.h>
int main(void)
{
  int N,i,j,min,tmp,count=0,flag;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(i=0;i<N;i++)
  {
    min=i;
    flag=0;
    for(j=i;j<N;j++)
    {
      if(A[j]<A[min]) {min=j; flag=1;}
    }
    if(flag==1) count++;
    tmp=A[i];
    A[i]=A[min];
    A[min]=tmp;
  }
  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d",A[N-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}

