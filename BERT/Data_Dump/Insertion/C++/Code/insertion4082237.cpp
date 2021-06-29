#include <stdio.h>

void trace(int A[],int N){
    int i;
    for(i = 0; i<N;i++){
        if(i) printf(" ");//学习!
        printf("%d",A[i]);
    }
    printf("\n");
}

void insertionSort(int A[],int N){
    int i,j,v;
    for (i=1;i<N;i++){
        v = A[i];
        j = i-1;
        while(j>=0&&A[j]>v){//找之前已排序部分的需要移动的元素。
                A[j+1] = A[j];
                j--;
        }
        A[j+1] = v;//插入排序的后移之后的赋值。

        trace(A,N);
    }
}

int main(){
    int N,i,j;
    int A[100];
    scanf("%d",&N);

    for(i=0; i<N;i++){
        scanf("%d",&A[i]);
    }
    trace(A,N);
    insertionSort(A,N);

    return 0;

}
