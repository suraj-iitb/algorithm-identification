#include<stdio.h>
#define Maxn 100000
#define Maxq 50000

int main()
{
  int i=0,k=0,n,q,mid,left,right;
  int A[Maxn],B[Maxq];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&B[i]);
    }

  
  for(i=0;i<q;i++)
    {
      left=0;
      right=n;

      
      while(left<right)
	{
	  mid=(left+right)/2;
	  if(B[i]==A[mid])
	    {
	      k++;
	      break;
	    }
	  if(B[i]>A[mid])
	    {
	      left=mid+1;
	    }
	  else if(B[i]<A[mid])
	    {
	      right=mid;
	    }
	}
    }
  printf("%d\n",k);

  return 0;
}
