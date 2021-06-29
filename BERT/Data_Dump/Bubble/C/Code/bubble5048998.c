#include<stdio.h>

int main()
{
  int i,j,n,alt,cnt=0;

  scanf("%d",&n);

  int a[n];

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&a[i]);
    }

  for(i = 0 ; i < n ; i++)
    {
      for(j = n-1 ; j > i ; j--)
	{
	  if(a[j] < a[j-1])
	    {
	     alt = a[j];
	     a[j] = a[j-1];
	     a[j-1] = alt;
	     cnt += 1;
	    }
	}
    }

  for(i = 0 ; i < n ; i++)
    {
      printf("%d",a[i]);
      if(i != n-1) printf(" ");
      else printf("\n");
    }
  printf("%d\n",cnt);
  
  return 0;
}

