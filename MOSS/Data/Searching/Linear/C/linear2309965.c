#include<stdio.h>
#define N 10000

int search(int*, int, int);

int main(){
  int i ,S[N+1],n,q,key,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(search(S,n,key)==1)
	{
	  count++;
	}
    }
  printf("%d\n",count);
  return 0;
}
int search(int S[],int n , int k)
{
  int i = 0;
  S[n]=k;
  while(S[i]!=k)
    {
      i++;
    }
  if(i == n)return 0;
  return 1;
}
    
