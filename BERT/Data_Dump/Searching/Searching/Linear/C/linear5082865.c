#include<stdio.h>

int Serch(int n, int a, int A[])
{
  int i=0;
  while(a!=A[i])
  {
    i++;
    if(i==n) return 0;
  }
  return 1;
}

int main()
{
  int a,n,q,i,S[10000],T[500],c=0;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0; i<q; i++) scanf("%d",&T[i]);

  for(i=0; i<q; i++)
  {
    a=T[i];
    if(Serch(n,a,S)) c++;
  }

  printf("%d\n",c);

  return 0;
}
