#include <stdio.h>
/*
int swap(){
}*/

int main (){
    int N = 0;
    int A[100] = {0};
    int tmp, flag, j, i, k=0;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    
    
    flag = 1; // 逆の隣接要素が存在する
    while(flag){
        flag = 0;
        for(j=N-1; j>=1; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                k++;
                flag = 1;
                
                
/*                
                for(i=0; i<N-1; i++){
                    printf("%d ", A[i]);
                }printf("%d\n%d\n", A[N-1], k);
*/
            }
        }
    }
    
    for(i=0; i<N-1; i++){
        printf("%d ", A[i]);
    }printf("%d\n%d\n", A[N-1], k);
    
    
return 0;
}



