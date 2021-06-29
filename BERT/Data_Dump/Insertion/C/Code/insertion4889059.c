#include<stdio.h>

void insertionSort(int *A,int N){
    int temp=0,j=0;
    for(int i=1;i<N;i++){
        temp = A[i];
        j= i - 1;
        while(j>=0 && A[j]>temp){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    
        for(int k=0;k<N;k++){
            if(k==N-1){
                printf("%d\n",A[k]);
            }
            else{
                printf("%d ",A[k]);
            }
        }    
    }
}

int main(void){
    int N=0;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    for(int k=0;k<N;k++){
        if(k==N-1){
            printf("%d\n",A[k]);
        }
        else{
            printf("%d ",A[k]);
        }
    }

    insertionSort(A,N);

    return 0;
}
