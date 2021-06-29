#include <stdio.h>

#define A 100

int main()
{
  int i,j,minj,N,a[A],flag,count=0;

  scanf("%d",&N);
  for(i=0 ; i < N ; i++)
    scanf("%d",&a[i]);
  for(i=0 ; i < N ; i++)
    {
      minj=i;
      for(j=i ; j < N ; j++)
        if(a[j] < a[minj]) minj=j;
      if(i != minj)
        {
          flag=a[i];
          a[i]=a[minj];
          a[minj]=flag;
          count++;
        }
    }
  for(i=0 ; i < N-1 ; i++)
    printf("%d ",a[i]);
  printf("%d\n",a[N-1]);
  printf("%d\n",count);

  return 0;
}
