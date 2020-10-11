#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define AMAX 10000

int main()
{
  unsigned short *X,*Y;

  int o,i,j;
  int B[AMAX+1];

  scanf("%d",&o);

  X = malloc(sizeof(short) * o + 1);
  Y = malloc(sizeof(short) * o + 1);

  for(i=0;i<=AMAX;i++) B[i] = 0;

  for(i=0;i<o;i++)
    {
      scanf("%hu",&X[i+1]);
      B[X[i+1]]++;
    }

  for(i=1;i<=AMAX;i++) B[i] = B[i] + B[i-1];

  for(j=1;j<=o;j++)
    {
      Y[B[X[j]]] = X[j];
      B[X[j]]--;
    }

  for (i=1;i<=o;i++)
    {
      if(i>1)printf(" ");
      printf("%d",Y[i]);
    }
  printf("\n");

  return 0;
}

