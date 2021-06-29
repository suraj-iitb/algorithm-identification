#include <stdio.h>

int main()
{
  int n, m, i, j, k, l, x, cnt=0;

  scanf("%d",&n);
  int a[n];

  for(i=0; i<n; i++) scanf("%d",&a[i]);

  scanf("%d",&m);

  for(i=0; i<m; i++)
  {
    int x;
    scanf("%d",&x);

    int k=-1,l=n+1;

    while(k+1!=l)
    {
      int m=(k+l)/2;
      if(a[m]==x)
      {
	      cnt++;
	      break;
      }

      if(a[m]<x) k=m;
      else l=m;
    } 
  }
  printf("%d\n",cnt);

  return 0;
}
