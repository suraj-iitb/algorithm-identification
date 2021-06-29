#include<stdio.h>

int main(){
    int N;
    int A[200];
    int i, j, k;
    int nmin, tmp;
    int count=0;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    for(i=0; i<N-1; i++){
        nmin = i;
        for(j=i+1; j<N; j++){
            if(A[j]<A[nmin]){
                nmin = j;
            }
        }
        if(i!=nmin){
            tmp = A[i];
            A[i] = A[nmin];
            A[nmin] = tmp;
            count += 1;
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
