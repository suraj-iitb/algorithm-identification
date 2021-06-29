#include<stdio.h>
void insertionSort(int A[],int N){
    int i,j,v;

    for(i=0;i<N;i++){
        if(i!=0){
            v=A[i];
            j=i-1;
            while(j>=0&&A[j]>v){
                A[j+1]=A[j];
                A[j]=v;
                j--;
            }
            for(j=0;j<N;j++){
                if(j!=N-1){
                    printf("%d ",A[j]);
                }else{
                    printf("%d\n",A[j]);
                }
            }
        }else{
            for(j=0;j<N;j++){
                if(j!=N-1){
                    printf("%d ",A[j]);
                }else{
                    printf("%d\n",A[j]);
                }
            }
        }

    }
}
int main(void){
    int i,A[100],N;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    insertionSort(A,N);

    return 0;
}
