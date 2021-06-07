#include<stdio.h>
#define N 100000
int isIncluded(int);//binary search
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
  int head=0;
  int tail=n-1;
  int middle=(head+tail)/2;
  for(;;)
    {
      if(x==arr[middle]) return 1;
      if(head>tail) break;
      else if(x>arr[middle]) head=middle+1;
      else tail=middle-1;
      middle=(head+tail)/2;
    }
  return 0;
}

