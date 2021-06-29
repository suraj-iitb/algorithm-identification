#include<stdio.h>
int main(void){
    int N,j,temp,flag=1,A[100],sum=0;
    
    scanf("%d",&N);
    for(j=0;j<N;j++)scanf("%d",&A[j]);
    
    while(flag){
        flag=0;
        for(j=N-1;j!=0;j--){
            if(A[j]<A[j-1]){
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
                flag=1;
                sum++;
            }
        }
    }
    
    for(j=0;j<N;j++){
        printf("%d",A[j]);
        if(j!=N-1)printf(" ");
    }
    
    printf("\n%d\n",sum);
}
