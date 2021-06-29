#include<stdio.h>
int main(void){
    int N,A[100],i,j,flag=1,count=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    while(flag){
        flag=0;
        for(i=0;i<N-1;i++){
            if(A[i]>A[i+1]){
                j=A[i];
                A[i]=A[i+1];
                A[i+1]=j;
                flag=1;
                count++;
            }
        }
    }
    for(i=0;i<N;i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
