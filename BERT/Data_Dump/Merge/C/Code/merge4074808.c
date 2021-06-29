#include<stdio.h>
#include<stdlib.h>

#define MAX 500000

int n, s[MAX+1];
int count = 0;

void mergeSort(int, int);
void merge(int, int, int);

int main()
{
  int i;
  
  scanf("%d", &n);
    for( i = 0; i < n; i++)
      {
	scanf("%d", &s[i]);
      }

    mergeSort(0,n);
   
   for( i = 0; i < n-1; i++)
      {
	printf("%d ", s[i]);
      }
   printf("%d\n", s[i]);
   printf("%d\n", count);
   
  return 0;
}

void merge(int left,int mid, int right)
{
  int *l, *r;
  int n1, n2, i, j, k;
  int inf=1000000000;
  n1 = mid-left;
  n2 = right-mid;

  l = malloc(sizeof(int)*(n1+1));
  r = malloc(sizeof(int)*(n2+1));

  for(i = 0; i < n1; i++)
    {
      l[i] = s[left+i];
    }
  l[n1] = inf;
  for( i = 0; i < n2; i++)
    {
      r[i] = s[mid+i];
    }
  r[n2] = inf;


  /*
  printf("l:");
 for(i = 0; i <= n1; i++)
    {
      printf("%d ", l[i]);
    }
 printf("r:");
for( i = 0; i <= n2; i++)
    {
     printf("%d ", r[i]);
    }

 printf("\n");
  */

 
  i = 0;
  j = 0;
  
  for(k = left; k < right;k++)
    {
      if(l[i] <= r[j])
	{
	  s[k] = l[i];
	  i++;
	}
      else
	{
	  s[k] = r[j];
	  j++;
	}
      count++;
    }
  return;
}

void mergeSort(int left, int right)
{
  int mid;

   if(left+1 < right)
    {
      mid = (right+left) / 2;
      mergeSort(left, mid);
      mergeSort(mid, right);
      merge(left,mid,right);
    }
   return;
}

