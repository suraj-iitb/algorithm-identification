#include<stdio.h>

int binarySearch(int [],int,int);

int main()
{
  int S[100000],key,n,q,i,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(binarySearch(S,n,key)!=0)c++;
    }
  printf("%d\n",c);

  return 0;
}

int binarySearch(int S[],int n,int key)
{
  int left=0,right=n,mid;
  while(left<right)
    {
      mid=(left+right)/2;
      if(S[mid]==key)return mid;
      else if(key<S[mid])right=mid;
      else left=mid+1;
    }
  return 0;
}
