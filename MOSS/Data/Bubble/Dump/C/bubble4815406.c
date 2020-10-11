#include<stdio.h>
#include<math.h>

int main(void){
    int A[101],N,i,j,flag,tmp,count=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
        flag = 1;
        while(flag){
            flag = 0;
            for(j=N-1;j>i;j--){
                if(A[j] < A[j-1]){
                    tmp=A[j];
                    A[j]=A[j-1];
                    A[j-1]=tmp;
                    flag = 1;
                    count++;
                }
            }
        }
    }
    for(j=0;j<N;j++){
        printf("%d",A[j]);
        if(j<N-1)printf(" ");
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
