#include <stdio.h>
#include <string.h>
#define MAX1 10000
#define MAX2 500
int a[MAX1];
int linearSearch(int,int);

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
      x=linearSearch(b[i],n);
      if(x==1) count=count+1;   
    }
 
 printf("%d\n",count);  
  return 0;
}


int linearSearch(int key,int n)
{
  int i; 
  i=0;
  a[n]=key;
  while(a[i]!=key)
    {
      i++;
      if(i==n)
	{
	  return 0;
	}
    }
  if(i!=n) return 1;
}
