#include<stdio.h>

int main()
{
  int i,j,n,alt,cnt=0,mini;

  scanf("%d",&n);

  int a[n];

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d",&a[i]);
    }

  for( i = 0 ; i < n ; i++)
    {
      mini = i;
      
      for(j = i ; j < n ; j++)
	{
	  if(a[j] < a[mini])
	    {
	      mini = j;
	    }
	}
      if(i != mini)
	{
      alt = a[i];
      a[i] = a[mini];
      a[mini] = alt;
      cnt +=1;
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

