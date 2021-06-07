#include <stdio.h>

int ser(int*,int,int);

int main()
{
  int A[10000+1],sum = 0,i,n,q,key;

  scanf("%d",&n);
  for(i=0;i<n;i++)
      scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(ser(A,n,key))
	sum++;
    }
  printf("%d\n",sum);

  return 0;
}

int ser(int A[],int n,int key)
{
  int i=0;
  A[n]= key;
  while(A[i] !=key)
    i++;
  return i != n;
}
  


  

