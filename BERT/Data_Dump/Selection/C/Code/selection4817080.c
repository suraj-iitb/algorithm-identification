#include<stdio.h>
int main(void){
    int A[101],N,minj,i,j,tmp,count=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++){
        minj=i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        tmp=A[i];
        A[i]=A[minj];
        A[minj]=tmp;
        if(A[i]!=A[minj])count++;
    }
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i<N-1)printf(" ");
    }
    printf("\n%d\n",count);
    return 0;
}
