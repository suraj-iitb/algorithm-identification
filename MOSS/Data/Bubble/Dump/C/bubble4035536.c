#include <stdio.h>

int main()
{
  static int flag=0,i,j,N,A[110],temp,cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  flag = 1;
  while(flag>0)
  {
    flag = 0;
    for(i=N-1;i>=0;i--)
    {
      if(A[i]<A[i-1])
      {
        temp=A[i];
        A[i]=A[i-1];
        A[i-1]=temp;
        flag = 1;
        cnt++;
      }
    }
  }
  for(i=0;i<N;i++)
  {
   printf("%d",A[i]);
   if(i!=N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

