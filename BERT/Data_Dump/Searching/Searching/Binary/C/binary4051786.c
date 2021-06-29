#include<stdio.h>
#define N 100000

int main(){
  
  int i, j, n, m, num, cnt = 0, right, left, center, array[N];
  
  scanf("%d",&n);

  for(i = 0; i < n ; i++)scanf("%d",&array[i]);
  
  scanf("%d",&m);

  for(i = 0; i < m ; i++)
    {
      scanf("%d",&num);

      right = n - 1, left = 0;
      
      while(1)
	{
	  center = (right + left)/2;
	  
	  if(right == left)
	    {
	      if(array[center] == num)cnt++;
	      break;
	    }
	  
	  if(array[center] == num)
	    {
	      cnt++;
	      break;
	    }
	  
	  if(array[center] > num)
	    {
	      right = center;
	      continue;
	    }

	  if(array[center] < num)
	    {
	      left = center + 1;
	      continue;
	    }
	} 
    }
  printf("%d\n",cnt);
  
  return 0;
}

