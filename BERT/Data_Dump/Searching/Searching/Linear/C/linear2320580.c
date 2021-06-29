#include <stdio.h>

int linearSearch(int*, int, int);

int main()
{
  int n, q, S[10000+1], T, C=0;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if( linearSearch(S, n ,T) ) C++;
  }

  printf("%d\n",C);
  return 0;
}

int linearSearch(int S[], int n, int T)
{
  int i=0;
  S[n]=T;
  while(S[i] != T) i++;
  return i != n;
}
