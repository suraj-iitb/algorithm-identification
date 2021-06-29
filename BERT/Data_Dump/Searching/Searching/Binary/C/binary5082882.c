#include<stdio.h>

int binarySearch(int n, int key, int A[])
{
    int right,mid,left = 0;
    right = n;
    while(left < right)
    {
        mid = (left + right)/2;
        if(A[mid] == key) return 1;
        else if (key < A[mid]) right = mid;
        else left = mid + 1;
    }
    return 0;
}

int main()
{
  int a,i,n,q,S[100000],T[50000],c=0;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0; i<q; i++) scanf("%d",&T[i]);

  for(i=0; i<q; i++)
  {
    a=T[i];
    if(binarySearch(n,a,S)) c++;
  }

  printf("%d\n",c);

  return 0;
}
