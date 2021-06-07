#include<stdio.h>
#include<stdlib.h>
int N,Q,S[100005],T,C,i;
 
int c(int *a,int *b)
{
    return *a-*b;
}
int main()
{
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",S+i);
    scanf("%d",&Q);
    for(i=0;i<Q;i++)
    {
        scanf("%d",&T);
        if(bsearch(&T,S,N,sizeof(int),c)!=NULL)
            C++;
    }
    printf("%d\n",C);
    return 0;
}
