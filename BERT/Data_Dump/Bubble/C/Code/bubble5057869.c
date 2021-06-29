#include<stdio.h>

int main()
{
  int n,i,j,v;
  int times=0;
  int A[100];
  scanf("%d",&n);
  for(i=0;i<=n-1;i++) scanf("%d",&A[i]);
  for(i=1;i<=n-1;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v)
        {
          A[j+1]=A[j];
          j--;
          times++;
        }
      A[j+1]=v;
    }
  for(i=0;i<=n-1;i++){
    if(i==n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",times);
  return 0;
}

