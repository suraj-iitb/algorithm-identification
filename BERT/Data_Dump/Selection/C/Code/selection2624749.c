#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int *A,int N){
    int i,j,minj;
    int count=0;
    for(i=0;i<N-1;i++){//i?????´??????????????°
        minj=i;
        for(j=i;j<N;j++){//????°???????????????????
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(A[minj]!=A[i]){
            swap(&A[i],&A[minj]);
            count++;
        }
    }
    return count; 
}

int main(){
    int A[100];
    int i,N,count;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    count = selectionSort(A,N);
    for(i=0;i<N;i++){
        if(i==0){
            printf("%d",A[i]);
        }else{
            printf(" %d",A[i]);
        }
    }
    printf("\n%d\n",count);
    return 0;
}
