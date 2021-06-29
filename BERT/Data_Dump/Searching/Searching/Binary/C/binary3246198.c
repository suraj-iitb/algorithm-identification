#include<stdio.h>

int main()
{
  int count = 0;
  int n1, n2;
  int t;
  int s=0, l, m;
  scanf("%d", &n1);
  int arr[n1];
  for(int i = 0; i < n1; i++)
    {
      scanf("%d", &arr[i]);
    }
  scanf("%d", &n2);
  for(int i = 0; i < n2; i++)
    {
      scanf("%d", &t);
      l = n1;
      s = 0;
      while(s <= l)
	{
	  m = (s+l)/2;
	  
	  if(arr[m] == t)
	    {
	      count++;
	      break;
	    }
	  else if(arr[m] > t)
	    {
	      l = m-1;
	    }
	  else
	    {
	      s = m+1;
	    }
	}
    }
  printf("%d\n", count);
}

