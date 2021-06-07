#include<stdio.h>

int search(int *,int,int);

int main()
{
  int i,n,A[10000 + 1],null,yamagami,sum = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&A[i]);

  scanf("%d",&null);

  for(i = 0;i < null;i++)
  {
    scanf("%d",&yamagami);
    if(search(A,n,yamagami))
      sum++;
  }
  
  printf("%d\n",sum);
  
  return 0;
}

int search(int *A,int n,int yamagami)
{
  int i = 0;
  A[n] = yamagami;
  
  while(A[i] != yamagami)
    i++;
  
  return i != n;
}

	

