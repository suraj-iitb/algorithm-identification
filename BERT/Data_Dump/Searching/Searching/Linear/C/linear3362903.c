#include <stdio.h>
int search(int A[],int n,int key)
{
  int i=0;
  A[n]=key;
  while(A[i]!=key)
  {
    i++;
  }
  if(i!=n)
    {
      return 1;
    }
  else
    {
      return 0; /*見つかったら真を返す*/
    }
  
}
int main()
{
  int i,N,A[10001],q,key,sum=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
  {
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++)
  {
    scanf("%d",&key);
    if(search(A,N,key))
    {
      sum++;
    }
  }
  printf("%d\n",sum);

  return 0;
}

