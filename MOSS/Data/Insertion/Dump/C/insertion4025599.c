#include<stdio.h>
#define N 1000

int main(){

  int i, j, temp, n, array[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++)scanf("%d",&array[i]);

  for(i = 0; i < n; i++)
    {
      temp = array[i];

      for(j = i - 1; j >= 0; j--)
	{
	  if(array[j] > temp)
	    {
	      array[j + 1] = array[j];
	      array[j] = temp;
	    }
	      else {
	    array[j + 1] = temp;
	    break;
	  }
	}
      for(j = 0; j < n; j++)
	{
	  if(j == n - 1)
	    {
	      printf("%d\n",array[j]);
	      break;
	    }
	  printf("%d ",array[j]);
	}
    }
  return 0;
}

