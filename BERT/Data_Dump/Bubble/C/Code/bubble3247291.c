#include<stdio.h>

int main(void)
{
    int N,i,j,flag,count;
    
        scanf("%d",&N);
        int A[N];
        for(i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }

        flag=1;
        count=0;
        while(flag)
        {
            flag=0;
            for(j=N-1;j>0;j--)
            {
                if(A[j]<A[j-1])
                {
                    int a=A[j];
                    A[j]=A[j-1];
                    A[j-1]=a;
                    flag=1;
                    count++;
                }
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

