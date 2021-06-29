#include <stdio.h>
int main(){
    int N;
    int i, j, tmp;
    int flag = 1;
    int count = 0;

    scanf("%d",&N);
    int A[N];

    for(i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    
    while (flag){
        flag = 0;
        for(j = N-1; j > 0; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    
    for(j = 0; j < N; j++){
        if(N-1 == j){
            printf("%d\n",A[j]);
        }else{
            printf("%d ",A[j]);
        }
    }
    printf("%d\n",count);

    return 0;
}

