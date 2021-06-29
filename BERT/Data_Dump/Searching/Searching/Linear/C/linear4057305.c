#include <stdio.h>
#define N 10000
int tansaku(int a[],int n,int fig);
int main()
{
  int i,n,fig,a[N+1],b,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&fig);
  for(i=0;i<fig;i++){
    scanf("%d",&b);
    if(tansaku(a,n,b))
      sum++;
  }
  printf("%d\n",sum);
  return 0;
}
int tansaku(int a[],int n,int b)
{
  int c=0;
  a[n]=b;
  while(a[c]!=b)
    c++;
  return c!=n;
}

