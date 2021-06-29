#include<stdio.h>

int binarysearch(int,int,int*);

int main()
{
  int n,q,key,s[100000];
  int i,count=0;
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
  {
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0 ; i<q ; i++)
  {
    scanf("%d",&key);
    if( binarysearch(n,key,s)==0 ) count++;
  }   
  printf("%d\n",count);
  return 0;
}

int binarysearch(int n,int key,int *s)
{
  int right=n,left=0,mid;
  while( left<right )
  {
    mid=(left+right)/2;
    if( s[mid]==key ) return 0;
    else if( s[mid]<key )
      left=mid+1;
    else if( s[mid]> key)
      right=mid;  
  }
  return 1;
}  

