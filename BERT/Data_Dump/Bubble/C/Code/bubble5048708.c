#include <stdio.h>

#define A 100

int main()
{
  int i,j,N,a[A],count=0,flag;

  scanf("%d",&N);
  for(i=0 ; i < N ; i++)
    scanf("%d",&a[i]);
  for(i=0 ; i < N-1 ; i++)
    {
      for(j=N-1 ; j > i ; j--)
        {
          if(a[j] < a[j-1])
            {
              flag=a[j-1];
              a[j-1]=a[j];
              a[j]=flag;
              count++;
            }
        }
    }
  for(i=0 ; i < N-1 ; i++)
    printf("%d ",a[i]);
  printf("%d\n",a[N-1]);
  printf("%d\n",count);

  return 0;
}
