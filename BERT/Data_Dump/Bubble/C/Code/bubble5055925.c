#include<stdio.h>

int main() {
  int i,j,A[1000],N,key,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N;i++)
    {
      for(j=N-1;j!=i;j--)
        {
          if(A[j]<A[j-1])
            {
              key=A[j];
              A[j]=A[j-1];
              A[j-1]=key;
              count++;
            }
        }
    }
  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i<N-1)printf(" ");
      else printf("\n%d\n",count);
    }
  return 0;
}

