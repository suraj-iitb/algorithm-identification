#include<stdio.h>
#define N 100

int main()
{
  int i,j,n=0,num[N],min=0,kari=0,count=0;

  scanf("%d",&n);
  for( i = 0 ; i < n ; i++ )
  {
    scanf("%d",&num[i]);
  }

  for( i = 0 ; i < n ; i++ )
  {
    min = i;

    for( j = i ; j < n ; j++)
    {
      if( num[j] < num[min] )
      {
        min = j;
      }
    }
    if( num[min] != num[i] )count++;
    
    kari = num[min];
    num[min] = num[i];
    num[i] = kari;
  }

  for( i = 0 ; i < n-1 ; i++ )
  {
    printf("%d ",num[i]);
  }
  printf("%d\n%d\n",num[n-1],count);

  return 0;
}

