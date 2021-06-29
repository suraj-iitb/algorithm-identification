#include<iostream>
#include<cstdio>
using namespace std;
void trace(int a[],int n)
{
  for(int i = 0;i<n;i++)
     {
       if(i>0) printf(" ");
       printf("%d",a[i]);
     }
  printf("\n");
}
void insertionsort(int a[],int n)
{
  int v,j;
  for(int i = 1;i<n;i++)
  {
    v = a[i];
    j  = i-1;
    while(j>=0 && a[j]>v)
    {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    trace(a,n);
  }
}
int main (){
  int n,a[104];
  scanf("%d",&n);
  for(int i = 0;i<n;i++)
     scanf("%d",&a[i]);
  trace(a,n);
  insertionsort(a,n);
  return 0 ;
}

