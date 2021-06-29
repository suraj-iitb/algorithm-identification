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

void bubbleSort(int* A,int N){
    bool flag = true;
    while(flag){
        flag = false;
        for(int j = N-1;j>=1; j--){
            if(A[j] < A[j-1]){
                int buff = A[j];
                A[j] = A[j-1];
                A[j-1] = buff;
                flag = true;
            }
        }
    }
    return;
}

void bubbleSort(int* A,int N,int* count){
    *count = 0;
    //printf("  %d\n",*count);
    bool flag = true;
    while(flag){
        flag = false;
        for(int j = N-1;j>=1; j--){
            if(A[j] < A[j-1]){
                int buff = A[j];
                A[j] = A[j-1];
                A[j-1] = buff;
                flag = true;
                *count += 1;
                //printf("  %d\n",*count);
            }
        }
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


    bubbleSort(Num,Len,&count);
    PRINT(Num,Len);
    printf("%d\n",count);


    return 0;
}

