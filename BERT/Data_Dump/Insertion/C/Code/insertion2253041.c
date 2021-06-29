#include<stdio.h>

int main()
{
  int i, j, k, v, n, a[100];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }

  for(i=1; i<n; i++)
    {
      for(k=0; k<n; k++)
	{
	  printf("%d", a[k]);
	  if(k+1<n)printf(" ");
	}
      printf("\n");
  
      v = a[i];
      j = i-1;
      while(j>=0 && a[j]>v)
	{
	  a[j+1] = a[j];
	  j--;
	}
      a[j+1] = v;
    }

  for(i=0; i<n; i++)
    {
      printf("%d", a[i]);
      if(i+1<n)printf(" ");
    }
  printf("\n");
  
  return 0;
}
