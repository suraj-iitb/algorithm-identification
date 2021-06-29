#include<stdio.h>
int main(){
    int i, j, minj, temp, N, cnt=0;
    int A[100];
    
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    for(i =0; i< N-1; i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] != A[minj]){
            cnt++;
        }
        temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
    }
    
    i = 0;
    while(1){
        printf("%d",A[i]);
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

