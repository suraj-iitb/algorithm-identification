#include"stdio.h"
#include"stdlib.h"
int main()
{
  int n;
  int i,j;
  int *A;
  int min;
  int buf;
  int count=0;
  scanf("%d",&n);
  A=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<n;i++)
    {
      min=i;
      for(j=i;j<n;j++)
        {
          if(A[j]<A[min])
            {
              min=j;
            }
        }
      if(i!=min)
        {
          buf=A[i];
          A[i]=A[min];
          A[min]=buf;
          count++;
        }
    }

  printf("%d",A[0]);
  for(i=1;i<n;i++)
    {
      printf(" %d",A[i]);
    }
  printf("\n%d\n",count);
  return 0;
}
