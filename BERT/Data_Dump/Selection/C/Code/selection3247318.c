#include<stdio.h>

int main(void)
{
    int N,i,j,minj,count;
    
        scanf("%d",&N);
        int A[N];
        for(i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }

        count=0;
        for(i=0;i<N;i++)
        {
            minj=i;
            for(j=i;j<N;j++)
            {
                if(A[j]<A[minj])
                {
                    minj=j;
                }
            }
            if(minj!=i)
            {
                int a=A[i];
                A[i]=A[minj];
                A[minj]=a;
                count++;
            }
            
        }
        
        
        for(i=0;i<N;i++)
        {
            printf("%d",A[i]);
            if(i==N-1) printf("\n");
            else printf(" ");
        }
        printf("%d\n",count);

}
