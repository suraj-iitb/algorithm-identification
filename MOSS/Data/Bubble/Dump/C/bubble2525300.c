#include<stdio.h>
int main(){
    int A[100];
    int N,i,sw;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    sw=bubbleSort(A,N);
    for(i=0;i<N;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d",sw);
    printf("\n");
    return 0;
}

int bubbleSort(int A[],int N){
    int i=0,flag=1,sw=0;
    int j,t;
    while(flag){
        flag=0;
        for(j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
               t=A[j];
               A[j]=A[j-1];
               A[j-1]=t;
               flag=1;
               sw++;
            }
        }
        i++;
    }
    return sw;
}
