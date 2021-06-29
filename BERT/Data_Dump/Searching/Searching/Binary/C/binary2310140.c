#include<stdio.h>

int Search(int);

int S[1000000],n;
int main(){
  int i,q,key,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
   
      scanf("%d",&S[i]);
    }

  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&key);
      if(Search(key)==1)
	{
	  count++;
	}
    }
  printf("%d\n",count);
  return 0;
}
int Search(int k)
{
  int left =0,right = n;
  int mid;
  while(left<right){
      mid=(left+right)/2;
      if(k==S[mid])return 1;
      if(k > S[mid])left = mid+1;
      else if(k < S[mid])right = mid;
    }
  return 0;
}
