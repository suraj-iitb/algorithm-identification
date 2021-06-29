#include<stdio.h>
#include<stdlib.h>

int binarySearch(int);
int S[100000],T[100000];
int n,q;

int main()
{
  int c=0,i;

  scanf("%d",&n);
  
  for(i = 0;i < n;i++)
    {
      scanf("%d",&S[i]);
     
    }
  scanf("%d",&q);
 

  for(i = 0;i < q;i++)
    {
      scanf("%d",&T[i]);
      
      c += binarySearch(T[i]);
    }

  printf("%d\n",c);

  return 0;
}

int binarySearch(int key)
{
  int left = 0,right = n,mid;

  while(left < right)
    {
      mid = (left + right)/ 2;
      if(S[mid] == key)return 1;
      else if(key < S[mid])right = mid;
      else left = mid + 1;
    }
      return 0;

 
   
}

