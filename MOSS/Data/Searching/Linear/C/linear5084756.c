#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *,int ,int);

int main()
{
  int n,q;
  int *S,*T;
  int i,C=0;

  scanf("%d",&n);
  if(!(n<=10000)) exit(1);

  S = (int *)malloc(sizeof(int)*n+1);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      if(!(S[i]>=0 && S[i]<=1000000000)) exit(2);
    }

  scanf("%d",&q);
  if(!(q<=500)) exit(2);

  T = (int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
      if(!(T[i]>=0 && T[i]<=1000000000)) exit(3);
      C +=linearSearch(S,n,T[i]);
    }

  free(S);
  free(T);
  printf("%d\n",C);
  return 0;
}

int linearSearch(int S[],int n,int key)
{
  int i=0;
  S[n] = key;
  while(S[i]!=key)
    {
      i++;
    }
  if(i==n) return 0;
  return 1;
}
