#include <stdio.h>

int main()
{
    int i,j,v,n,u;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }

  for(u=0;u<n;u++){
    if(u==n-1){
      printf("%d\n",A[u]);
    }
    else{
      printf("%d ",A[u]);
    }
  }

  // N個の要素を含む0-オリジンの配列A
  for(i=1;i<=n-1;i++)
    {
      v = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > v)
        {
          A[j+1] = A[j];
          j--;
          A[j+1] = v;
        }
      for(u=0;u<n;u++){
             if(u==n-1){
                printf("%d\n",A[u]);
            }
            else{
                printf("%d ",A[u]);
            }   
        }
    }
    return 0;
}
