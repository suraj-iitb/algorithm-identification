#include<stdio.h>
int main()
{
    int n,x,i,j,key;
    int A[110];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    scanf("%d",&A[i]);
    for(i=1;i<=n;i++)
    { key= A[i];
      j=i-1;
      while(j>0 && A[j]>key)
      {
          A[j+1]=A[j];
          j=j-1;
      }
      A[j+1]=key;
      for(x=1;x<=n;x++)
      {
          if(x==n)printf("%d\n",A[x]);
          else printf("%d ", A[x]);
      }
        
    }
    return 0;
}
