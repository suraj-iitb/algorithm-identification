#include <stdio.h>
int A[100];
 

void printSequence(int len, int num){
    int i;
    for(i = 0; i<len; i++){
        if(i != 0)printf(" ");
        printf("%d",A[i]);
    }
 
    printf("\n");
    printf("%d\n",num);
 
}
 
int main(){
    int key = 0, num = 0, len, i, j, minj;
 
    scanf("%d", &len);
    for(i = 0; i<len; i++){
        scanf("%d",&A[i]);
    }
 

    for(i = 0;i <= len - 1;i++){
        minj = i;
        for(j = i; j <= len - 1;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
 
        if(minj != i){
            key = A[i];
            A[i] = A[minj];
            A[minj] = key;
            num++;
        }
    }
 
    printSequence(len, num);
 
    return 0;
}
