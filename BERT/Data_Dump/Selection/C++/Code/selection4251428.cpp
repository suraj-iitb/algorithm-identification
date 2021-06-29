#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void PRINT(int* A,int Len){
    for(int i = 0;i<Len-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[Len-1]);
    return;
}

void selectionSort(int* A,int N){
    for(int i = 0;i<N;i++){
        int minj = i;
        for(int j=i;j < N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        int buff = A[i];
        A[i] = A[minj];
        A[minj] = buff;
    }
    return;
}

void selectionSort(int* A,int N,int* count){
    *count = 0;
    for(int i = 0;i<N;i++){
        int minj = i;
        for(int j=i;j < N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(minj != i){
            *count += 1;
        }
        int buff = A[i];
        A[i] = A[minj];
        A[minj] = buff;
    }
    return;
}

int main(){
    
    int Len,count;
    scanf("%d",&Len);
    int Num[Len];

    for(int i = 0;i<Len;i++){
        scanf("%d",&Num[i]);
    }


    selectionSort(Num,Len,&count);
    PRINT(Num,Len);
    printf("%d\n",count);


    return 0;
}

