#include<stdio.h>

#define N 1000

int main()
{
  int i,j;
  int n,key;
  int a[N];

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
    }

  /* for(i = 0; i < n-1; i++)
  {
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);*/
  
  for(i = 0; i < n; i++)
  {
    key = a[i];
    j = i -1;
    while(j >= 0 && a[j] > key)
      {
	a[j+1] = a[j];
	j--;
      }
    a[j+1] = key;
    
    for(j = 0; j < n-1; j++)
    {
      printf("%d ",a[j]);
    }
  
    printf("%d\n",a[j]);
  
  }
  
  
  return 0;
}

