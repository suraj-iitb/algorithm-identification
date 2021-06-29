#include<stdio.h>
#define N 1000000

int main()
{
  int i,j,key,n,q,cnt=0,left=0,right=0,mid=0,S[N],T[N]/*,swap,flag=1*/;

  scanf("%d",&n);
  for(i=0;i<n;i++)
      scanf("%d",&S[i]);

  /*
  while(flag)
    {
      flag = 0;
      for(j=n-1;j>=1;j--)
	{
	  if(S[j] < S[j-1])
	    {
	      swap = S[j];
	      S[j] = S[j-1];
	      S[j-1] = swap;
	      flag = 1;
	    }
	}
    }
  */
  
  scanf("%d",&q);
  i = 0;
  while(i<q)
    {
      scanf("%d",&T[i]);
      for(j=0;j<i;j++)
	if(T[i] == T[j]) break;
      if(i == j) i++;
    }

 
  for(i=0;i<q;i++)
    {
      left = 0;
      right = n;
      key = T[i];
      while(left < right)
	{
	  mid = (left+right)/2;
	  if(S[mid] > key) right = mid;
	  else if(S[mid] < key) left = mid + 1;
	  else
	    {
	      cnt++;
	      break;
	    }
	}
    }
	
	printf("%d\n",cnt);
    return 0;
}




