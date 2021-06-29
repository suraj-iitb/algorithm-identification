#include <stdio.h>
#define M 100000
#define N 50000
#define NOT_FOUND -1

int cnt=0,n;

int binarysearch(int x[],int key)
{
  int left=0,right=n,mid;

  while(left<right)
    {
      mid=(left+right)/2;
      if(x[mid]==key)return mid;
      else if(key<x[mid])right=mid;
      else left=mid+1;
    }
  return NOT_FOUND;
}

    
int main(){
  int y[M],z[N],i,j;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&y[i]);

   scanf("%d",&j);
   for(i=0;i<j;i++){
    scanf("%d",&z[i]);
   }
   for(i=0;i<j;i++)
     if(binarysearch(y,z[i])!=NOT_FOUND)cnt++;

   printf("%d\n",cnt);
   return 0;
}


  
    
    
  

