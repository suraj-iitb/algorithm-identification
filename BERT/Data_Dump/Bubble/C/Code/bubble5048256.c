#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,flag,tmp,cnt;
  int n;
  scanf("%d",&n);
  if(n < 1 || n > 100)
    {
      printf("Error\n");
      exit(1);
    }

  int a[n];
  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
      if(a[i] < 0 || a[i] > 100)
	{
	  printf("Error\n");
	  exit(2);
	}
    }
  /*for(i = 0; i < n; i++)
    {
      printf("%d",a[i]);
      if(i == n-i)printf("\n");
      else printf(" ");
      }*/
  flag = 1;

   while(flag)
    {
      flag = 0;
      {
	for(i = n-1; i >0; i--)
	  {
	    if(a[i] < a[i-1])
	      {
		tmp = a[i];
		a[i] = a[i -1];
		a[i-1] = tmp;
		flag = 1;
		cnt++;
	      }
	  }
      }
    }
  for(i = 0; i < n; i++)
    {
      printf("%d",a[i]);
      if(i == n-1)printf("\n");
      else printf(" ");
    }
  printf("%d\n",cnt);
  return 0;
}

