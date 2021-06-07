#include <stdio.h>
#include<string.h>
int binarysearch(int a[],int key,int n)
{  int left=0,right=n,mid;
   while(left<right)
   {  mid=(left+right)/2;
      if(a[mid]==key)  return mid;
      else if(key<a[mid])  right=mid;
      else left=mid+1;
   }
   return 0;
}
int main()
{  int a[1000000],b[1000000];
   int i,n,t,k,m;
   m=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf("%d",&a[i]);
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {  scanf("%d",&b[i]);
      if(binarysearch(a,b[i],n))  m++;
   }
   printf("%d\n",m);
   return 0;
}
