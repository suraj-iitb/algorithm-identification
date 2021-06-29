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


void insertionSort(int* A,int Len){
    for(int i = 1;i<Len;i++){
        int buff = A[i];
        int j = i-1;

        PRINT(A,Len);
        
        while(0 <= j && buff < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = buff;
    }
}

int main(){
    
    int Len;
    scanf("%d",&Len);
    int Num[Len];

    for(int i = 0;i<Len;i++){
        scanf("%d",&Num[i]);
    }


    insertionSort(Num,Len);
    PRINT(Num,Len);


    return 0;
}

