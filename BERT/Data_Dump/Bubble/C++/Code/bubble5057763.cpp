#include <stdio.h>

    int main ()
    {
    int A[100],i,j,flag=1,N,tmp,cnt=0;

    scanf("%d",&N);

    for(i=0;i<N;i++)
        {
        scanf("%d",&A[i]);
        }

    for(i=0;i<N;i++)
        {
        for(j=N-1;j>=i+1;j--)
        {
         if(A[j]<A[j-1])
         {
          tmp=A[j];
          A[j]=A[j-1];
          A[j-1]=tmp;
          cnt++;
         }
        }
        
        }

    for(i=0;i<N-1;i++)
        {
        printf("%d ",A[i]);
        }
        printf("%d",A[N-1]);
        printf("\n");
        printf("%d\n",cnt);
        return 0;
    }
