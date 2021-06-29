#include<stdio.h>
int main(void)
{
    int N,v,j;
    int A[1000];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[N-1]);
    for(int i=1;i<=N-1;i++){
        v=A[i];
        j=i-1;
        while((j>=0)&&(A[j]>v)){
            A[j+1]=A[j];
            j--;
            A[j+1]=v;
        }
        for(int i=0;i<N-1;i++){
            printf("%d ",A[i]);
        }
        printf("%d\n",A[N-1]);
    }
    return 0;
}
