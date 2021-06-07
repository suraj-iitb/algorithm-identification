#include <stdio.h>

int serch(int ,int []);

int n;

int main()
{
  int i,S[100000],q,T[50000],count = 0;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i = 0;i < q;i++)
    {
      scanf("%d",&T[i]);
      if(serch(T[i],S)) count++;
	}
    
  printf("%d\n",count);
  return 0;
}
int serch(int a,int S[])
{
  int mid,left = 0,right = n;
  while(left < right)
    {
      mid = (right + left) / 2;
      if(a == S[mid])
	{
	  return 1;
	} else if(a < S[mid])
	{
	  right = mid;
	} else if(a > S[mid])
	{
	  left = mid +1;
	}
    } 
  return 0;
}
  
    
      

