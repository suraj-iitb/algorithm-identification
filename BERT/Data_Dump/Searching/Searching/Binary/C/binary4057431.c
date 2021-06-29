#include<stdio.h>

#define N 100000
#define Q 50000

int binarysearch(int,int[],int);/*search*/

int main()
{
  int n,s[N],q,t,i,cnt=0,m;
  
  scanf("%d",&n);
  for(i=0 ; i<n ; i++)
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
    scanf("%d",&t);
    if(binarysearch(t,s,n))cnt++;
  }
  
  printf("%d\n",cnt);

  return 0;
}

int binarysearch(int x,int y[],int n)
{
  int left=0,right=n,mid;

  while(left<right)
    {
       mid=(left+right)/2;
       if(x == y[mid])
	 return 1;
       else if(y[mid]>x)
	 right=mid;
       else if(y[mid]<x)
	 left=mid+1;
  }
  return 0;
}

