#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#define PI 3.14159265359
#define N_MAX 1000
#define NUM 1000
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

void trace(int A[], int n)
{
  int i;
  for(i = 1; i <= n; i++)
    {
      if(i > 1) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n");
}

int main()
{
  int n, i, j, tmp;
  int A[N_MAX+1];
  scanf("%d",&n);
  for(i = 1; i <= n; i++) scanf("%d",&A[i]);
  trace(A,n);
  for(j = 2; j <= n; j++)
    {
      tmp = A[j];
      i = j - 1;
      while(i > 0 && A[i] > tmp)
	{
	  A[i+1] = A[i];
	  i--;
	}
      A[i+1] = tmp;
      trace(A,n);
    }
  return 0;
}
