#include <stdio.h>

void BubbleSort(int A[],int N){
    int flag = 1,i,j,temp,count=0;
    while(flag){
        flag=0;
        for(j=N-1;0<j;j--){
            if(A[j]<A[j-1]){
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
                
                flag=1;
                count++;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i<N-1) printf(" ");
    }
    printf("\n%d\n",count);
}

int main(){
    int i,N;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    BubbleSort(A,N);
    return 0;
}
