#include<stdio.h>
#include<math.h>
int main(void)
{
  int N,i,j,tmp,count=0;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  for(i=0;i<N;i++)
  {
    for(j=N-1;j>i;j--)
    {
      if(A[j]<A[j-1])
      {
        tmp=A[j];
        A[j]=A[j-1];
        A[j-1]=tmp;
        count++;
      }
    }
  }
  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d",A[N-1]);
  printf("\n%d\n",count);
  return 0;
}

