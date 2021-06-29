#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i = 1;
  int j;
  int key;
  int length;
  int *arrow;

  // Input
  scanf("%d", &length);
  arrow = (int *)malloc(sizeof(int) * length);
  for(i = 0; i < length; i++) scanf("%d", &arrow[i]);
  for(i = 0; i < length - 1; i++)
    {
      printf("%d ", arrow[i]);
    }
  printf("%d\n", arrow[length - 1]);


  for(i = 1; i < length; i++)
    {
    // sort 
      key = arrow[i];
      j = i - 1;
      while(i > 0 && arrow[j] > key)
	{
	  arrow[j+1] = arrow[j];
	  j = j - 1;
	}
      arrow[j+1] = key;

      // Output
      for(j = 0; j < length - 1; j++)
	{
	  printf("%d ", arrow[j]);
	}
      printf("%d\n", arrow[length - 1]);
    }

  return 0;
}
