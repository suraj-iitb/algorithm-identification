#include<stdio.h>

int main(){
    int N;
    int A[200];
    int i, j, k;
    int flag;
    int tmp, count=0;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    for(i=0; i<N; i++){
        for(j=N-1; j>i; j--){
            if(A[j]<A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count += 1;
            }
        }
    }

    for(i=0; i<N; i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }

    printf("\n%d\n", count);

    return 0;
}
