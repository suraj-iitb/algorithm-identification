#include<stdio.h>

int search(int,int,int*);

int main()
{
  int n,q,t[500],s[10000];
  int i,count=0;
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
  {
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0 ; i<q ; i++)
  {
    scanf("%d",&t[i]);
    if( search(n,t[i],s)==0 ) count++;
  }   
  printf("%d\n",count);
  return 0;
}

int search(int n,int key,int *s)
{
  int i=0;
  s[n]=key;
  while( s[i] != key)
  {
    i++;
    if( i==n ) return 1;
  }  
  return 0;
}  

