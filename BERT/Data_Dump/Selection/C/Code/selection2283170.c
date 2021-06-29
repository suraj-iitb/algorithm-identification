#include<stdio.h>
 
int N,A[100],c=0,i,j,t;
 
int main()
{
    for(i=0,scanf("%d",&N);i<N;scanf("%d",&A[i++]));
    for(i=0;i<N;i++)
    {
        for(t=j=i;j<N;j++)
            if(A[j]<A[t])
                t=j;
        if(i!=t)
        {
            A[i]^=A[t]^=A[i]^=A[t];
            c++;
        }
    }
    for(i=0;i<N;i++)
        printf("%d%s",A[i],i==N-1?"\n":" ");
    printf("%d\n",c);
    return 0;
}
