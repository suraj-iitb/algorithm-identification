#include<stdio.h>

int main()
{
  int n,i,k,b=0,q;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&k);
      if(sensearch(&A[0],n,k))b++;
    }
  printf("%d\n",b);

  return 0;
}

int sensearch(int *A,int n,int k)
{
  int i=0;
  A[n]=k;
  while(A[i]!=k)i++;

  return i != n;
}


