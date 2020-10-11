#include <stdio.h>
#define k 2000001
int a[k],b[k],c[k];


int main()
{

  int n,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
    }
  for(i=0;i<k;i++)
    {
      c[i] = 0;
    }
  for(j=1;j<=n;j++)
    {
      c[a[j]]++;
    }
  for(i=1;i<k;i++)
    {
      c[i] = c[i] + c[i-1];
    }
  for(j=n;j>=1;j--)
    {
      b[c[a[j]]] = a[j];
      c[a[j]]--;
    }
  for(i=1;i<=n;i++)
    {
      printf("%d",b[i]);
      if(i!=n)
	{
	  printf(" ");
	}
      else
	{
	  printf("\n");
	} 
    }
  return 0;
}
