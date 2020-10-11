#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define XMAX 10000

int main(void)
{
  unsigned short *X, *Y;
  
  int Z[XMAX+1];
  int h, i, j;
  scanf("%d",&h);
  
  X = malloc(sizeof(short)*h+1);
  Y = malloc(sizeof(short)*h+1);
  
  for(i=0;i<=XMAX;i++) Z[i] = 0;
  
  for(i=0;i<h;i++) {
    scanf("%hu",&X[i+1]);
    Z[X[i+1]]++;
  }
  
  for(i=1;i<=XMAX;i++) Z[i] = Z[i] + Z[i-1];
  
  for(j=1;j<=h;j++) {
    Y[Z[X[j]]] = X[j];
    Z[X[j]]--;
  }
  
  for(i=1;i<=h;i++) {
    if(i>1) printf(" ");
    printf("%d",Y[i]);
  }
  printf("\n");
  
  return 0;
}

