        #include <stdio.h>
        int main()
        {
            int N,A[100],i,flag=1,key,num=0;
            scanf("%d",&N);
            for(i=0;i<N;i++)
            {
                scanf("%d",&A[i]);
            }
            while(flag)
            {
                flag=0;
                for(i=N-1;i>=1;i--)
                {
                    if(A[i]<A[i-1])
                    {
                    key=A[i];
                    A[i]=A[i-1];
                    A[i-1]=key;
                    flag=1;
                    num++;
                }
            }
        }
        for(i=0;i<N;i++)
        {
            printf("%d",A[i]);
            if(i!=N-1)printf(" ");
        }
        printf("\n%d\n",num);
        return 0;
        }
