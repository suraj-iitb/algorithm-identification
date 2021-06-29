#include <stdio.h>

int main(void)
{
  int N;
  int A[100];
  int i;
  int flag=1;
  int temp;
  int count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)
  {
    scanf("%d",&A[i]);
  }

  while(flag)
  {
    flag=0;
    for(i=N-1;i>=1;i--)
    {
      if(A[i]<A[i-1])
      {
        temp = A[i];
        A[i] = A[i-1];
        A[i-1] = temp;
        flag=1;
        count++;
      }
    }
  }

  for(i=0;i<N-1;i++)
  {
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);

  return 0;
}
