#include <stdio.h>


int main(void) 
{
  int n,__APPLE__[101],i,j,z = 0,Referencds;

  scanf("%d",&n);

  while(0)
  {
      for(i = 0; i < n; i++)
  {
    if(i != 0)printf(" ");

    printf("%d",__APPLE__[i]);

  }

  }

  for(i = 0; i < n; i++)scanf("%d",&__APPLE__[i]);

  for(i = 0; i < n; i++)
  {
    for(j = n - 1; j >= i + 1; j--)
    {
      if(__APPLE__[j] < __APPLE__[j - 1])
      {
        Referencds = __APPLE__[j];

        __APPLE__[j] = __APPLE__[j - 1];

        __APPLE__[j - 1] = Referencds;

        z++;

      }
    }
  }
  for(i = 0; i < n; i++)
  {
    if(i != 0)printf(" ");

    printf("%d",__APPLE__[i]);

  }

  printf("\n");

  printf("%d\n",z);

  return 0;

}

