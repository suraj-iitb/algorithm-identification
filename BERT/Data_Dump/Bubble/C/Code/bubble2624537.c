#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int *A,int N){
    int i,j;//i?????´?????????????????°
    int count=0;
    for(i=0;i<N;i++){
        for(j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                swap(&A[j],&A[j-1]);
                count++;
            }
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
    count = bubbleSort(A,N);
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
