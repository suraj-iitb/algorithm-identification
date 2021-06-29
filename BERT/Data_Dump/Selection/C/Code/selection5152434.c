    #include <stdio.h>

    int main ()
    {
    int A[100],i,j,minj,N,g,cnt=0;

    scanf("%d",&N);

    for(i=0;i<N;i++)
        {
        scanf("%d",&A[i]);
        }

    for(i=0;i<N;i++)
        {
        minj=i;
        for(j=i;j<N;j++)
        {
            if(A[j]<A[minj])
            {
                minj = j;
            }
        }
        g = A[i];
            A[i]=A[minj];
            A[minj]=g;
            if(minj!=i)
            cnt++;
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


