#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define VMAX 10000

int main()
{
  int c[VMAX+1],a[MAX],b[MAX];
  int i,j,n,k=0;
  scanf("%d",&n);
  for(i=1 ; i <= n ; i++)
    {
      scanf("%d",&a[i]);
      if(k < a[i]) k = a[i];
    }
  for (i=0 ; i <= k ; i++)
    c[i] = 0;
  for (j=1 ; j <= n ; j++)
    c[a[j]]++;
  for (i=1 ; i <= k ; i++)
    c[i] = c[i] + c[i-1];
  for (j=n ; j >= 1 ; j--)
    {
      b[c[a[j]]] = a[j];
      c[a[j]]--;
    }
  for(i=1 ; i <= n ; i++)
    {
      if(i > 1)printf(" ");
      printf("%d",b[i]);
    }
  printf("\n");
  return 0;
}
