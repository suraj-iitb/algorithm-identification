#include <stdio.h>
#include <stdlib.h>
#define MAX 2000002
#define VMAX 10000

void countingSort(int);

short unsigned int *a, *b;

int main(){
 
  int c[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  a = malloc(sizeof(short)*n+1);
  b = malloc(sizeof(short)*n+1);

  for(i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
    
  countingSort(n);

  for(i = 0; i < n-1; i++)
    {
      printf("%d ", b[i]);
    }
  printf("%d", b[i]);
  printf("\n");
  
  return 0;
}

void countingSort(int n)
{
  int i,sum;
  int c[VMAX];

  for( i = 0; i < VMAX; i++)c[i] = 0;
  
  for( i = 0; i < n; i++)
    {
      c[a[i]]++;
    }
  for(i = 1;i <= VMAX; i++)
    {
      c[i] = c[i] + c[i-1];
    }
  for(i = n-1; i >= 0; i--)
    {
      b[c[a[i]]-1] = a[i];
      c[a[i]]--;
    }

  return;
}

