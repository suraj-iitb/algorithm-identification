#include <stdio.h>

#define A 1000

int main()
{
  int array[A];
  int i;
  int num;//打ち込む個数
  int v;
  int j;
  int k;

  scanf("%d",&num);

  for(i = 0; i<num ;i++)
    {
      scanf("%d",&array[i]);
    }
 
  for(k=0 ; k < num ; k++)
    {
      printf("%d",array[k]);
      if(k<num-1)printf(" ");
    }
  printf("\n");

  for(i = 1 ; i <= num-1 ; i++)//ソート
    {
      v = array[i];
      j = i - 1;

      
      while(j >= 0 && array[j] > v)
	{
	  array[j+1] = array[j];
	  j--;
	}
      array[j+1] = v;

      for(k=0 ; k < num ; k++)
	{
	  printf("%d",array[k]);
	  if(k<num-1)printf(" ");
	}
      if(i<=num-1)printf("\n");
    }
  return 0;
}
