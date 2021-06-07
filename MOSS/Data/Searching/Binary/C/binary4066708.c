#include <stdio.h>

#define N 100000
#define Q 50000

int func(int,int [N],int);
  
int main()
{
  int i,j,n,q;
  int S[N],T[Q];
  int count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {   
      scanf(" %d",&S[i]);
    }
  
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {   
      scanf(" %d",&T[i]);
    }

  for(i=0;i<q;i++)
    {
      count += func(n,S,T[i]);
      //printf("%d:",i);
      //printf("%d\n",count);
    }
  printf("%d\n",count);
  
  return 0;
}

int func(int n,int S[N],int key)
{
  int left=0,mid,right=n;
  while(left<right)
    {
      mid = (left + right)/2;
      if(key>S[n-1]||key<S[0])return 0;
      if(key == S[mid])return 1;
      if(key>S[mid])
	{
	  left = mid+1;
	}
      else if(key<S[mid])
	{
	  right = mid;
	}
    }
  return 0;
}

