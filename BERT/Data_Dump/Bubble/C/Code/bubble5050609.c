#include<stdio.h>

int main(){
    int N, i, j, flag, temp, cnt = 0;
    int A[100];
    
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    
    flag = 1;
    while(flag){
        flag = 0;
        for(j = N-1; j >= 1;j--){
            if(A[j]< A[j-1]){
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = 1;
                cnt++; 
            }
        }
    }
    
    i = 0;
    while(1){
        printf("%d", A[i]);
        if(i >= N-1){
            printf("\n");
            break;
        }
        else{
            printf(" ");
            i++;
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
