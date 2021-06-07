#include<stdio.h>
#define N 10005
int search(int *,int ,int);
  int main()
{
  int n,A[N],q,B,found = 0,i;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&B);
    
      if(search(A,n,B)) found++;
    }
  printf("%d\n",found);

  return 0;
}

int search(int A[] ,int n, int B)
{
  int k=0;
  A[n] = B;
  while(A[k] != B)k++;
  return k !=n;
    }

