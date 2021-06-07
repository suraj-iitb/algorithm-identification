#include<stdio.h>

int linearSearch(int *,int,int);

int main()
{
  int i,n,q,key;
  int A[10000],sum=0;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&A[i]);
    }

  scanf("%d",&q);

  for(i = 0; i < q; i++)
    {
      scanf("%d",&key);

      if(linearSearch(A,n,key))sum++;
    }
  printf("%d\n",sum);

  return 0;
}

  int linearSearch(int A[],int n,int key)
  {
    int i = 0;
    A[n] = key;

    while(A[i] != key)i++;

    return i != n;
  }
      
    

