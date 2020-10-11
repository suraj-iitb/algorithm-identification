#include <stdio.h>

void CountingSort();
int A[2000000],n;

int main()
{

  int i;
  scanf("%d",&n);

  for( i = 0 ; i <n ; i++)scanf("%d",&A[i]);

  CountingSort();
}

void CountingSort()
{

  int C[10001],i,j=0;
  for(i = 0; i < 10001 ; i++) C[i] =0;

  for(i = 0;i<n ; i++)
    {
      C[A[i]]++;
    }
  
  for(i = 0 ; i <= 10000 ; i++)
    {
      while(C[i] > 0)
        {
          if(j == n-1)
            {
              printf("%d",i);
              break;
            }
          printf("%d ",i);
          C[i]--;
          j++;
        }

      //printf("\n");
    }

  printf("\n");
}
