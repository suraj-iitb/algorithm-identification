#include<stdio.h>
#define N 10000
int isIncluded(int);
int arr[N];//first line
int n;//the number of first line
int main(void)
{
  int i;//counter
  int q;//the number of second line
  int x;//the element of second array
  int ans=0;//output
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&arr[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    {
      scanf("%d",&x);
      ans+=isIncluded(x);
    }
  printf("%d\n",ans);
  return 0;
}
int isIncluded(int x)
{
  int i;//counter
  for(i=0;i<n;i++)
    {
      if(arr[i]==x) return 1;
    }
  return 0;
}

