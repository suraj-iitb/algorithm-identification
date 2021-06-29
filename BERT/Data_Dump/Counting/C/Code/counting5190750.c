#include <stdio.h>
#define STACK 2000000
#define STOCK 10001

void cs(int,int);

int X[STACK];
int Y[STACK];
int Z[STOCK];


int main()
{
  int n, k = 0, i;
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    scanf("%d", &X[i]);
    if(k < X[i]) k = X[i];
  }

  cs(k, n);

  printf("%d", Y[0]);

  for(i=1;i<n;i++) printf(" %d", Y[i]);
  printf("\n");

  return 0;
}


void cs(int k, int n)
{
  int i;

  for(i=0;i<=k;i++)
    {
      Z[i] = 0;
    }

  for(i=0;i<n;i++)
    {
    Z[X[i]]++;
    }

  for(i=1;i<=k;i++)
    {
      Z[i] = Z[i] + Z[i-1];
    }

  for(i=n-1;i>=0;i--)
  {
    Y[Z[X[i]]-1] = X[i];
    Z[X[i]]--;
  }

}



