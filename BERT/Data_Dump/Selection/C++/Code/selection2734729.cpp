#include<iostream>
#include<cstdio>
using namespace std;
int selectionsort(int a[],int n)
{
  int min,ans = 0,j,t;
  for(int i = 0;i<n-1;i++)
    {
      min = i;
      for( j = i;j<n;j++)
      {
        if(a[j]<a[min])
           min = j;
         }
    t = a[i];a[i] = a[min]; a[min] = t;
    if(i!=min) ans+=1;
    }
   return ans;
}
int main ()
{
  int a[103],n,sw;
  scanf("%d",&n);
  for(int i = 0;i<n;i++)
    scanf("%d",&a[i]);
  sw = selectionsort(a,n);
  for(int i = 0;i<n;i++)
    {
      if(i<n-1) printf("%d ",a[i]);
      else printf("%d",a[i]);
      }
  printf("\n");
  printf("%d\n",sw);
  return 0 ;
}

