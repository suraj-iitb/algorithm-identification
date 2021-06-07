#include <stdio.h>
int binarySearch(int [], int, int);

int main()
{
  int i,j,n,q,key,A[100000],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&j);
      A[i]=j;
    }
  
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      
      //      binarySearch(A, n, key);
      if(binarySearch(A, n, key)==1)
	{
	  count++;
	  //printf("%d",key);
	}
    }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int A[],int n,int key)
{
  int left=0,right=n,mid;
  while(left<right)
    {
      mid = (left+right)/2;
      if(A[mid]==key)
	{
	  return 1;
	}
      if(key<A[mid])
	{
	  right = mid;
	}
      else if(key>A[mid])  left = mid + 1;
      // return 0;
    }
   return 0;
}
 



      

