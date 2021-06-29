#include<stdio.h>

int main(){
  int n,h,i,j,v;
  int A[110];
  scanf("%d",&n);
  for(i=0;i<=n-1;i++) scanf("%d",&A[i]);
  for(i=0;i<=n-1;i++){
    if(i==n-1)  printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  for(i=1;i<=n-1;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v)
        {
          A[j+1]=A[j];
          j=j-1;
        }
      A[j+1]=v;
      for(h=0;h<=n-1;h++)
        {
          if(h==n-1) printf("%d\n",A[n-1]);
          else printf("%d ",A[h]);
        }
    }
    return 0;
}
