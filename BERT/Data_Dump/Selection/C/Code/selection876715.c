#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#define PI 3.14159265359
#define N_MAX 100
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))

void swap(int *a,int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void Selectionsort(int a[],const int n)
{
  int i, j, min_index, count = 0;
  for(i = 1; i <= n; i++)
    {
      min_index = i;
      for(j = i; j <= n; j++)
	{
	  if(a[j] < a[min_index]) min_index = j;
	}
      if(min_index != i)
	{
	  swap(&a[i],&a[min_index]);
	  count++;
	}
    }
  for(i = 1; i <= n; i++)
    {
      printf("%d",a[i]);
      if(i != n) printf(" ");
    }
  printf("\n%d\n",count);
}

int main()
{
  int i,n,a[N_MAX+1];
  scanf("%d",&n);
  for(i = 1; i <= n; i++) scanf("%d",&a[i]);
  Selectionsort(a,n);
  return 0;
}
