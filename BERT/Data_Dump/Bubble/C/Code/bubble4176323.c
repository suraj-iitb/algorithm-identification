/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int bubbleSort(int A[], int N){
    int sw = 0;
    int tmp;
    int flag = 1;
    int j;
    
    while(flag){
        flag =0;
        for (j=N-1; j>0; --j){
            if(A[j] <A[j-1]){
            tmp = A[j]; A[j] = A[j-1]; A[j-1] = tmp;
            flag =1;  //交換が起きたらflagが1になるけど、交換が無かったら0のままなのでwhileループが止まる
            sw++;
        }
        }
    }
    return sw;
}

int main(){
    int A[100];
    int N;
    int i;
    int sw;
    
    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    sw = bubbleSort(A,N);
    
    for (i = 0; i<N; i++){
        if(i > 0) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",sw);
}
