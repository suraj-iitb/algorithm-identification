#include<stdio.h>
int N, i, j, k, n, A[100] = { 1001 };

main(){
    scanf("%d",&N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    
    for(i=0; i<N; i++){
        n = A[i];
        for(j=i-1; j>=0; j--){
            if(n < A[j]){
                A[j+1] = A[j];
                A[j] = n;
            }
        }
        
        for(k=0; k<N; k++){
            printf("%d",A[k]);
            if(k != N-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
}

