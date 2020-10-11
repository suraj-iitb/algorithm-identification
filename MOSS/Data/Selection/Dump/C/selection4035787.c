#include <stdio.h>

int main()
{
  int flag=1,i,j,minj,N,A[100],temp,cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N;i++)
  {
    minj = i;
    for(j=i;j<N;j++)
    {
      if(A[j]<A[minj])minj=j;
    }
    if(A[i]==A[minj])continue;
    else
    {
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      cnt++;
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

