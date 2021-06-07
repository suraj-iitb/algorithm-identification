#include <stdio.h>
#define MAX1 100000
#define MAX2 50000
int binarySearch(int,int);
int a[MAX1];
int main()
{
  int n,q,i,b[MAX2],x,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&b[i]);
    }

  for(i=0;i<q;i++)
    {
      x=binarySearch(b[i],n);
      if(x==1)
        {
          count=count+1;
        }
    }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int key,int n)
{
  int left=0,right=n,mid;
  while(left<right)
    {
      mid=(left+right)/2;
      if(a[mid]==key)
        {
          return 1;
        }
      else if(key<a[mid])
        right=mid;
      else left=mid+1;
    }
  return 0;
}
