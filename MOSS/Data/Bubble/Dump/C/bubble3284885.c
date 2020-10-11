#include<stdio.h>
#define X 100
int main(){
    int A[X],N,i,j,k,flag=1,count=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    while(flag){
        flag=0;
        for(j=N-1;j>0;j--){
            k=A[j];
            if(A[j]<A[j-1]){
                A[j]=A[j-1];
                A[j-1]=k;
                flag=1;
                count++;
            }
        }
    }
    for(i=0;i<N-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[i]);
    
    printf("%d\n",count);
    
    return 0;
}

