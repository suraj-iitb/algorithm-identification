#include<stdio.h>

int main()
{
    int A[10000];
    int n,i,b,j,c=0;
    scanf("%d",&n);
    for(i=0;i<10000;i++){
        A[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&b);
        A[b]++;
    }
    for(i=0;i<10000;i++)
    {
        for(j=0;j<A[i];j++)
        {
            printf("%d",i);
            if(c<n-1){
                printf(" ");
                c++;
            }
        }
    }
    printf("\n");
    return 0;
}
