#include<stdio.h>

int main(){
    int i, j;
    int count = 0;
    int N, minj, tmp;
    scanf("%d",&N);
    int A[N];

    for(i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }

    for(i = 0; i < N; i++){
        minj = i;
        for(j = i; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(minj != i){
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            count++;
        }
        
    }

    for(j = 0; j < N; j++){
        if(N - 1 == j)printf("%d\n",A[j]);
	else printf("%d ",A[j]);
    }
    
    printf("%d\n",count);
    
    return 0;
}

