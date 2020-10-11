#include<stdio.h>
int main()
{
    int A[100],N,sum=0;
    int num=1,tum=0,a;
    scanf("%d",&N);
    for(a=0;a<N;a++)
    {
        scanf("%d",&A[a]);
    }
while(num==1){
    num=0;
    for(a=N-1;a>=1;a--)
    {
        if(A[a]<A[a-1])
        {
            tum=A[a];
            A[a]=A[a-1];
            A[a-1]=tum;
            sum++;
            num=1;
            
        }
    }
}
    for(a=0;a<N-1;a++)
    {
        printf("%d ",A[a]);
        
    }
    printf("%d\n",A[a]);
 printf("%d\n",sum);
 
    return 0;
}


