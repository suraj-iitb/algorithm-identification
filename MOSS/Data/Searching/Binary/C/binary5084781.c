#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *,int ,int);

int main()
{
  int n,q;
  int *S,*T;
  int i,C=0;

  scanf("%d",&n);
  if(!(n<=100000)) exit(1);

  S = (int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      if(!(S[i]>=0 && S[i]<=1000000000)) exit(2);
    }

  scanf("%d",&q);
  if(!(q<=50000)) exit(3);

  T = (int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&T[i]);
      if(!(T[i]>=0 && T[i]<=1000000000)) exit(3);
      C += binarySearch(S,n,T[i]);
    }

  printf("%d\n",C);

  free(S);
  free(T);
  return 0;
}

int binarySearch(int S[],int n,int key)
{
  int left = 0;
  int right = n;
  int mid;
  while(left<right)
    {
      mid = (left+right)/2;
      if(S[mid] == key) return 1;
      else if(key < S[mid]) right = mid;
      else left = mid+1;
    }
  return 0;
}
