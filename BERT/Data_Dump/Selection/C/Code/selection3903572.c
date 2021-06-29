
#include <stdio.h>

int main (){
    int N = 0;
    int A[100] = {0};
    int tmp, minj, j, i, k=0;
   
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    
    for(i=0; i<=N-1; i++){
        minj = i;
        for(j=i; j<=N-1; j++){
            if(A[j] < A[minj]){
                minj = j;
                //k++;
            }
        }
        if(A[i] > A[minj]){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            k++;
        }
    }
    
    for(i=0; i<N-1; i++){
        printf("%d ", A[i]);
    }printf("%d\n%d\n", A[N-1], k);
    
    
return 0;
}
